# Run with:
#       chmod +x tests/integration_test.sh
#       ./tests/integration_test.sh

#!/bin/bash

# Load server configuration
SERVER_CONFIG="server/config/server_config.json"
SERVER_PORT=$(jq -r '.server_port' "$SERVER_CONFIG")

# Log file for integration test results
INTEGRATION_LOG="logs/integration_test.log"

# Cleanup any previous log
> "$INTEGRATION_LOG"

# Start the server
echo "Starting the server on port $SERVER_PORT..." | tee -a "$INTEGRATION_LOG"
./server "$SERVER_PORT" &
SERVER_PID=$!

# Wait for the server to start
sleep 2

# Check if server started successfully
if ps -p $SERVER_PID > /dev/null; then
    echo "Server started successfully with PID: $SERVER_PID" | tee -a "$INTEGRATION_LOG"
else
    echo "Failed to start the server. Exiting." | tee -a "$INTEGRATION_LOG"
    exit 1
fi

# Start clients and connect them to the server
echo "Starting clients..." | tee -a "$INTEGRATION_LOG"

CLIENT1_CONFIG="config/client1_config.json"
CLIENT2_CONFIG="config/client2_config.json"

# Function to simulate a client
start_client() {
    CONFIG_FILE=$1
    CLIENT_NAME=$(jq -r '.username' "$CONFIG_FILE")
    SERVER_IP=$(jq -r '.server_ip' "$CONFIG_FILE")
    SERVER_PORT=$(jq -r '.server_port' "$CONFIG_FILE")
    
    echo "Starting client $CLIENT_NAME connecting to $SERVER_IP:$SERVER_PORT" | tee -a "$INTEGRATION_LOG"
    ./client "$SERVER_IP" "$SERVER_PORT" &
    CLIENT_PID=$!
    sleep 1

    if ps -p $CLIENT_PID > /dev/null; then
        echo "Client $CLIENT_NAME connected successfully with PID: $CLIENT_PID" | tee -a "$INTEGRATION_LOG"
    else
        echo "Failed to start client $CLIENT_NAME. Exiting." | tee -a "$INTEGRATION_LOG"
        kill $SERVER_PID
        exit 1
    fi

    echo $CLIENT_PID
}

CLIENT1_PID=$(start_client "$CLIENT1_CONFIG")
CLIENT2_PID=$(start_client "$CLIENT2_CONFIG")

# Wait for clients to be fully connected
sleep 2

# Simulate sending messages from Client 1 to Client 2
echo "Client1 sending message to Client2..." | tee -a "$INTEGRATION_LOG"
echo "Hello from Client1!" | nc localhost $SERVER_PORT

# Simulate sending messages from Client 2 to Client 1
echo "Client2 sending message to Client1..." | tee -a "$INTEGRATION_LOG"
echo "Hello from Client2!" | nc localhost $SERVER_PORT

# Wait for messages to be exchanged
sleep 3

# Check the log files or console output to verify message reception
# (You can expand this section with specific checks if you have server/client logs)

# Clean up: Stop clients and server
echo "Stopping clients and server..." | tee -a "$INTEGRATION_LOG"

kill $CLIENT1_PID
kill $CLIENT2_PID
kill $SERVER_PID

echo "Integration test completed." | tee -a "$INTEGRATION_LOG"
