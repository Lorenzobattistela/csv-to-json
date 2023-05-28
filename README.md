

# CLI CSV Converter

The CLI CSV Converter is a command-line tool built with three classes: `IO`, `CLI`, and `Converter`. It allows you to convert CSV files to JSON format.

## Usage

1. Compile the program using g++:

   ```bash
   g++ cli.cpp converter.cpp io.cpp -o cli
   ```

2. Run the program using the following command:

   ```bash
   ./cli jsonfile.json csvfile.csv separator
   ```

   Replace `jsonfile.json` with the desired name for the output JSON file, `csvfile.csv` with the input CSV file, and `separator` with the character used as the CSV separator.

## JSON Format

The generated JSON file will have the following format:

```json
{
  "data": [
    { "column1": "value", "column2": "value" },
    { "column1": "value", "column2": "value" }
  ]
}
```

Each row from the CSV file will be represented as a JSON object with column names as keys and corresponding values.

Feel free to test it with `test.csv` file.

---
