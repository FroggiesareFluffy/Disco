#include <iostream>
#include <fstream>
#include "Parser.h"

int main(int argc, char* argv[]) {
    char* output = NULL;
    char* filename = NULL;
    int i = 1;
    if (argc < 2){
        std::cout << "Usage: disco <filename> [-o <output>]";
    }
    while (i < argc) {
        if (std::string(argv[i]) == "-o"){
            output = argv[i+1];
            i += 2;
        } else {
            filename = argv[i];
            i++;
        }
    }
    Parser parser (filename, output);
    parser.parse();
    parser.writeOut();
    return 0;
}