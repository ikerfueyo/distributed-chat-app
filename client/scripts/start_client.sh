#!/bin/bash

# Load client configuration
CONFIG_FILE="config/client_config.json"
SERVER_IP=$(jq -r '.server_ip' $CONFIG_FILE)
SERVER_PORT=$(jq -r '.server_port' $CONFIG_FILE)
USERNAME=$(jq -r '.username' $CONFIG_FILE)

# Start the client with the specified configuration
echo "Starting client with server IP: $SERVER_IP, server port: $SERVER_PORT, username: $USERNAME"

./client $SERVER_IP $SERVER_PORT
