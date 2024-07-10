#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#ifndef MAIN_HPP
# define MAIN_HPP

bool check_input( int ac );
bool check_files( std::fstream &inputFile, std::fstream &outputFile );
void change_the_line( std::fstream &inputFile, std::fstream &outputFile,
    std::string &s1, std::string &s2);

#endif
