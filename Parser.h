//
// Created by John on 12/19/15.
//

#ifndef DISCO_PARSER_H
#define DISCO_PARSER_H


#include <vector>
#include <string>

class Parser {
    std::ifstream infile;
    std::ofstream outfile;
    std::vector<std::string> includes;
    std::vector<std::string> code;
    bool open;
public:
    Parser(char*, char*);

    void parse();

    void writeOut();
};


#endif //DISCO_PARSER_H
