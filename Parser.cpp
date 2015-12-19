//
// Created by John on 12/19/15.
//

#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Parser.h"

Parser::Parser(char *infilename, char *outfilename) {
    this->open = true;
    this->infile.open(infilename);
    this->outfile.open(outfilename);
    if (!this->infile.is_open()){
        std::cout << "Cannot open input file: " << infilename << std::endl;
        this->open = false;
    }
    if (!this->outfile.is_open()){
        std::cout << "Cannot open output file: " << outfilename << std::endl;
        this->open = false;
    }
}

void Parser::parse() {
    if (!this->open){
        return;
    }
    std::string line;
    while (getline(this->infile, line)){
        if (line.substr(0, 6) == "output"){
            if (std::find(this->includes.begin(), this->includes.end(), "<iostream>") == this->includes.end()){
                this->includes.push_back("<iostream>");
            }
            this->code.push_back("std::cout << "+line.substr(7, line.length())+" << std::endl");
        }
    }
    this->infile.close();
}

void Parser::writeOut() {
    for (int i = 0; i < this->includes.size(); ++i) {
        this->outfile << "#include " << this->includes[i] << std::endl;
    }
    this->outfile << std::endl << "int main(){" << std::endl;
    for (int i = 0; i < this->code.size(); ++i) {
        this->outfile << "    " << this->code[i] << ";" << std::endl;
    }
    this->outfile << "}";
    this->outfile.close();
}
