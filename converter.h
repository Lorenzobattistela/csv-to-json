#ifndef CONVERTER_H
#define CONVERTER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "utils.h"
#include "io.h"

class Converter {
    public:
        std::string json_filename;
        std::string csv_filename;
        char separator;
        CSV csv;
        std::vector<JSON_ITEM> json_items;

        Converter(const std::string& _json_filename, const std::string& _csv_filename, char _separator);

        void convert();
    
    private:
        void csv_to_json(CSV csv);
};

#endif
