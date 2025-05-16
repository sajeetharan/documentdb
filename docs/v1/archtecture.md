# Architecture

DocumentDB is implemented as a PostgreSQL extension. It hooks into PostgreSQL's parser, planner, executor, and storage layers.

Key architectural components include:
- BSON storage engine within PostgreSQL
- Query translation layer for document operations
- Optional MongoDB-compatible gateway for interfacing

This design ensures seamless integration with PostgreSQL’s transactional, indexing, and security features.
