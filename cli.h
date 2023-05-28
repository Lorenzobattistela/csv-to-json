#ifndef CLI_H
#define CLI_H

#include <iostream>
#include <string>
#include "converter.h"

class CLI {
    public:
        std::vector<std::string> args;

        CLI(char *args[]);

        int checkArgs();
};

#endif