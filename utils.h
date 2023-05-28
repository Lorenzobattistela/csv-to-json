#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <map>

struct CSV {
    std::vector<std::string> columns;
    std::vector<std::vector<std::string>> rows;
};

struct JSON_ITEM {
    std::map<std::string, std::string> data;
};

#endif