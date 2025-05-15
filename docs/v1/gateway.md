# DocumentDB Gateway

## Overview
The DocumentDB Gateway is a RESTful API that provides a simple and efficient way to interact with the DocumentDB database. It allows users to connect to the DocumentDB through Mongosh, and perform CRUD (Create, Read, Update, Delete) operations.

## Get Started
To get started with the DocumentDB Gateway, follow these steps:
        
1. **Build the Gateway**: Build the DocumentDB Gateway using the provided Dockerfile.
    ```bash
    docker build . -f .github/containers/Build-Ubuntu/Dockerfile_gateway -t <image-tag>
    ```
2. **Run the Gateway**: Run the DocumentDB Gateway in a Docker container.
    ```bash
    docker run -dt -p 10260:10260 -e USERNAME=<username> -e PASSWORD=<password> <image-tag>
    ```
3. **Connect to the Gateway**: Use Mongosh to connect to the DocumentDB Gateway.
    ```bash
    mongosh localhost:10260 -u <username> -p <password> \
        --authenticationMechanism SCRAM-SHA-256 \
        --tls \
        --tlsAllowInvalidCertificates
    ```

### Run locally
To run the DocumentDB Gateway locally, use cargo

2. **Run documentdb backend**:
    See README.md for instructions on how to run the backend
2. **Run the Gateway**:  Build the DocumentDB Gateway in the pg_documentdb_gw folder
    ```bash
    cd pg_documentdb_gw
    ./scripts/build_and_start_gateway.sh -u <username> -p <password>
    ```
3. **Connect to the Gateway**: Use Mongosh to connect to the DocumentDB Gateway.
    ```bash
    mongosh localhost:10260 -u <username> -p <password> \
        --authenticationMechanism SCRAM-SHA-256 \
        --tls \
        --tlsAllowInvalidCertificates
    ```