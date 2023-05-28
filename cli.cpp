#include <iostream>
#include <stdio.h>
#include <vector>
#include "converter.h" 
#include "cli.h"

using namespace std;

int main(int argc, char* argv[]) {
    CLI cli(argv);
    int checked = cli.checkArgs();
    if(checked == 1) {
        return 1;
    }

    Converter converter("test.json", "test.csv", ',');
    converter.convert();
    cout << "Converted CSV to JSON successfully" << endl;
    return 0;
}

CLI::CLI(char *args[]) {
    int i = 0;
    while (args[i] != nullptr) {
        this->args.push_back(args[i]);
        i++;
    }
}

int CLI::checkArgs() {
    if(this->args.size() != 4) {
        cout << "Usage: ./converter <json_filename> <csv_filename> <separator>" << endl;
        return 1;
    }

    if(this->args[3].size() != 1) {
        cout << "Separator must be a single character" << endl;
        return 1;
    }

    if(this->args[1].compare(this->args[1].size() - 5, 5, ".json") != 0) {
        cout << "JSON filename must end with .json" << endl;
        return 1;
    }

    if (this->args[2].compare(this->args[2].size() - 4, 4, ".csv") != 0) {
        std::cout << "CSV filename must end with .csv" << std::endl;
        return 1;
    }

    return 0;
}

