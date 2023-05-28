
#include "io.h"
#include "utils.h"
using namespace std;

IO::IO(const string& _filename, char _separator)
    : filename(_filename), separator(_separator) {}

vector<string> IO::read_csv_columns() {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Failed to open the file: " << filename << endl;
        return {};
    }

    string line;
    getline(fin, line);
    stringstream s(line);
    vector<string> columns;
    string column;

    while (getline(s, column, separator)) {
        columns.push_back(column);
    }

    return columns;
}

vector<vector<string>> IO::read_csv_rows() {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Failed to open the file: " << filename << endl;
        return {};
    }

    vector<vector<string>> rows;
    string line;
    getline(fin, line);

    while(getline(fin, line)) {
        stringstream s(line);
        string column;
        vector<string> row;

        while(getline(s, column, separator)) {
            row.push_back(column);
        }
        rows.push_back(row);
    }
    return rows;
}

CSV IO::get_csv() {
    csv.columns = read_csv_columns();
    csv.rows = read_csv_rows();
    return csv;
}

void IO::write_json(const vector<JSON_ITEM>& json_items, string json_filename) {
    ofstream fout(json_filename);
    if (!fout) {
        cerr << "Failed to open the file: " << filename << endl;
        return;
    }
    
    fout << "{\"data\":[\n";
    for (int i = 0; i < json_items.size(); i++) {
        fout << "    {\n";
        for (auto it = json_items[i].data.begin(); it != json_items[i].data.end(); it++) {
            fout << "        \"" << it->first << "\": \"" << it->second << "\"";
            if (next(it) != json_items[i].data.end()) {
                fout << ",";
            }
            fout << "\n";
        }
        fout << "    }";
        if (i != json_items.size() - 1) {
            fout << ",";
        }
        fout << "\n";
    }
    fout << "]}";
}
