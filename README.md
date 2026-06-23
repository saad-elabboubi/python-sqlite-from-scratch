# SQLite File Reader from Scratch

C++20 implementation of the CodeCrafters "Build Your Own SQLite" challenge.

The project focuses on SQLite storage internals rather than using SQLite as a
library. It reads SQLite database files directly and currently supports the
early challenge stages around database metadata.

## What it covers

- Binary parsing of SQLite database files
- SQLite database header fields
- Page-size parsing
- B-tree page metadata
- Table count extraction from the schema page
- A small command-line interface compatible with the CodeCrafters challenge

## Run locally

```sh
./your_program.sh sample.db .dbinfo
```

Expected output:

```text
database page size: 4096
number of tables: 3
```

## Build manually

```sh
cmake -B build -S .
cmake --build build
./build/sqlite sample.db .dbinfo
```

## Notes

This repository was originally generated from the CodeCrafters SQLite challenge
template and then implemented in C++20 as a systems/database-internals project.
