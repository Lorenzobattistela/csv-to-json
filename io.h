#ifndef IO_H
#define IO_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "utils.h"

class IO {
public:
    std::string filename;
    char separator;
    CSV csv;

    IO(const std::string& _filename, char _separator);
    
    CSV get_csv();

    void write_json(const std::vector<JSON_ITEM>& json_items, std::string json_filename);

private:
    std::vector<std::string> read_csv_columns();

    std::vector<std::vector<std::string>> read_csv_rows();
};

#endif
