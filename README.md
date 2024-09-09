### Distributed Chat Application


## Overview
This distributed chat application enables multiple clients to communicate with each other via a server in real-time. The application uses AES encryption for message confidentiality and RSA encryption for secure key exchange. The project demonstrates concepts such as client-server communication, encryption, and multi-threaded handling of multiple clients.

## Features
- Real-time communication: Supports real-time messaging between multiple clients via a central server.
- AES Encryption: Uses AES-256-CBC for encrypting the messages between clients and the server.
- RSA Encryption: Uses RSA for secure key exchange of AES keys between clients and the server.
- Multi-client support: The server can handle multiple clients simultaneously using multi-threading.
- Message broadcasting: Messages sent by a client can be broadcast to multiple recipients.
- Logging: Logs server and client activities.

## Setup Instructions
Dependencies:
- CMake (version 3.10 or higher)
- OpenSSL (for encryption functionality)
- GTest (for unit testing)
- GNU Make (or another build system)
- g++ or another C++ compiler
    `sudo apt-get update`
    `sudo apt-get install build-essential libssl-dev cmake git`
    `sudo apt-get install libgtest-dev`
Building the Application:
1. Clone the repository
    `git clone https://github.com/ikerfueyo/distributed-chat-app.git`
    `cd distributed-chat-app`
2. Create a build directory and compile the project
    `mkdir build`
    `cd build`
    `cmake ..`
    `make`

## Running
1. Make sure you have a valid RSA private key for the server and the server configuration file (`server/config/server_config.json`).
2. Run the server with the configuration file as an argument: `./server /server/config/server_config.json`
3. Make sure you have the RSA public key of the server, and the client configuration file (`client/config/client_config.json`).
4. Run the client with the configuration file as an argument: `./client /client/config/client_config.json`

## Testing
1. Build the tests
    `cd build`
    `make client_test server_test shared_test`
2. Run the tests
    `ctest --output-on-failure`

## Configuration
Server Configuration (`server_config.json`)
    `{`
        `"server_port": 12345,`
        `"max_clients": 100,`
        `"rsa_private_key_file": "/path/to/private_key.pem",`
        `"log_level": "INFO"`
    `}`
Client Configuration (`client_config.json`)
    `{`
        `"server_ip": "127.0.0.1",`
        `"server_port": 12345,`
        `"username": "client1",`
        `"rsa_public_key_file": "/path/to/public_key.pem"`
    `}`
