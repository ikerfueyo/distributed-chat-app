#!/bin/bash

# Load server configuration from the JSON file
CONFIG_FILE="config/server_config.json"
SERVER_PORT=$(jq -r '.server_port' $CONFIG_FILE)
MAX_CLIENTS=$(jq -r '.max_clients' $CONFIG_FILE)
ENCRYPTION_KEY=$(jq -r '.encryption_key' $CONFIG_FILE)
LOGGING_LEVEL=$(jq -r '.logging_level' $CONFIG_FILE)

# Display the server configuration being used
echo "Starting server on port: $SERVER_PORT"
echo "Max clients allowed: $MAX_CLIENTS"
echo "Encryption key: $ENCRYPTION_KEY"
echo "Logging level: $LOGGING_LEVEL"

# Start the server with the specified configuration
./server $SERVER_PORT
