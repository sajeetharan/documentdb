# CRUD Operations

You can perform standard Create, Read, Update, and Delete operations on BSON documents using SQL syntax.

Examples:
```sql
-- Insert
INSERT INTO documents (doc) VALUES ('{"name": "Alice", "age": 30}'::bson);

-- Read
SELECT doc->>'name' FROM documents WHERE doc->>'age' = '30';

-- Update
UPDATE documents SET doc = jsonb_set(doc, '{age}', '31') WHERE doc->>'name' = 'Alice';

-- Delete
DELETE FROM documents WHERE doc->>'name' = 'Alice';
yaml
Copy
Edit

---

### 📄 `v1/indexing.md`

```markdown
# Indexing

DocumentDB supports GIN and BTREE indexing on BSON paths.

Example:
```sql
CREATE INDEX idx_name ON documents ((doc->>'name'));
GIN indexes can also be used for full-text and array searches.

yaml
Copy
Edit

---

### 📄 `v1/querying.md`

```markdown
# Querying

DocumentDB leverages PostgreSQL's powerful SQL engine to query document data.

Supported operations include:
- Path-based extraction using `->` and `->>` operators
- Full-text search via `to_tsvector`
- Geospatial queries using `PostGIS`
- Vector similarity queries via `pgvector`

Example:
```sql
SELECT * FROM documents WHERE doc->>'status' = 'active';
yaml
Copy
Edit

---

### 📄 `v1/performance.md`

```markdown
# Performance

DocumentDB benefits from PostgreSQL's mature performance optimization:

- Parallel query execution
- Index-only scans
- Caching and WAL optimizations
- Integration with PostgreSQL's EXPLAIN/ANALYZE tooling

For best results, ensure critical document fields are indexed.