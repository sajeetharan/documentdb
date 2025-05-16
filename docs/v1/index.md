# Welcome to DocumentDB

**DocumentDB** is a fully open-source document-oriented database engine, built on PostgreSQL.

It supports seamless CRUD operations on BSON data types, full-text search, geospatial queries, and vector embeddings — all within the robust PostgreSQL ecosystem.


## 🛠️ Getting Started with DocumentDB

Begin your journey with DocumentDB by exploring its architecture, supported data types, core operations, and advanced capabilities. This section provides a step-by-step guide to help you understand, build, and run applications using DocumentDB.


[Introduction](v1/introduction.md)  
[Architecture](v1/architecture.md)  
[DocumentDB Gateway](v1/gateway.md)
[Data Types](v1/data-types.md)  
[CRUD Operations](v1/crud.md)  
[Indexing](v1/indexing.md)  
[Querying](v1/querying.md)  
[Performance](v1/performance.md)  
[Security](v1/security.md)  
[Use Cases](v1/use-cases.md)  
[Prebuild Image](v1/prebuild-image.md)  
[Packaging](v1/packaging.md)  
[FAQ](v1/faq.md)  

---

## 🚀 Features

- Native PostgreSQL extension with BSON support
- Powerful CRUD and indexing capabilities
- Support for full-text search, geospatial data, and vector workloads
- Fully open-source under the [MIT License](https://opensource.org/license/mit)
- On-premises and cloud-ready deployment

---

## 🧱 Components

- `pg_documentdb_core` – PostgreSQL extension for BSON type and operations
- `pg_documentdb` – Public API layer enabling document-oriented access
- `pg_documentdb_gw` – Gateway for DocumentDB, providing a MongoDB interface

---

## 🐳 Quick Start with Docker
### Prebuild Image For DocumentDB
There are prebuild images available for different platforms. You can find the list of prebuild images [here](v1/prebuild-image.md).

To run the prebuild image, use the following command:
```bash
# example for Ubuntu 22.04, PostgreSQL 16, amd64
# Choose the image tag according to your configuration
docker run -dt mcr.microsoft.com/cosmosdb/ubuntu/documentdb-oss:22.04-PG16-AMD64-0.103.0
docker exec -it <container-id> bash  
```

### Prebuild Image For DocumentDB with Gateway
To run the prebuild image with the DocumentDB Gateway, use the following command:
```bash
docker run -dt -p 10260:10260 -e USERNAME=<username> -e PASSWORD=<password> ghcr.io/microsoft/documentdb/preview:test

mongosh localhost:10260 -u <username> -p <password> \
        --authenticationMechanism SCRAM-SHA-256 \
        --tls \
        --tlsAllowInvalidCertificates
```

### Build DocumentDB from Source
```bash
git clone https://github.com/microsoft/documentdb.git
cd documentdb
docker build -f .devcontainer/Dockerfile -t documentdb .
docker run -v $(pwd):/home/documentdb/code -it documentdb /bin/bash
make && sudo make install
```

### How to Contribute

To contribute, see these documents:

- [Code of Conduct](./CODE_OF_CONDUCT.md)  
- [Security](./SECURITY.md)  
- [Contributing](./CONTRIBUTING.md)

### Community

- Please refer to page for contributing to our [Roadmap list](https://github.com/orgs/microsoft/projects/1407/views/1).
- [FerretDB](https://github.com/FerretDB/FerretDB) integration allows using DocumentDB as backend engine.

Contributors and users can join the [DocumentDB Discord channel in the Microsoft OSS server](https://aka.ms/documentdb_discord) for quick collaboration.

### License

**DocumentDB** is licensed under the MIT License. See [LICENSE](./LICENSE.txt) for details.

### Trademarks

This project may use trademarks or logos. Use of Microsoft trademarks must follow Microsoft’s [Trademark & Brand Guidelines](https://www.microsoft.com/en-us/legal/intellectualproperty/trademarks). Use of third-party marks is subject to their policies.