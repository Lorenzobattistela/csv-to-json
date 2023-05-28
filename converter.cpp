#include "converter.h"
#include "utils.h"
using namespace std;

Converter::Converter(const string& _json_filename, const string& _csv_filename, char _separator)
    : json_filename(_json_filename), csv_filename(_csv_filename), separator(_separator) {}

void Converter::convert() {
    IO io = IO(csv_filename, separator);
    CSV csv = io.get_csv();
    csv_to_json(csv);
    io.write_json(json_items, json_filename);
}

void Converter::csv_to_json(CSV csv) {
    for (int i = 0; i < csv.rows.size(); i++) {
        JSON_ITEM json_item;
        for (int j = 0; j < csv.columns.size(); j++) {
            json_item.data[csv.columns[j]] = csv.rows[i][j];
        }
        json_items.push_back(json_item);
    }
}

