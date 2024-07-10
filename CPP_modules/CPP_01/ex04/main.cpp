#include "main.hpp"

int main( int ac, char **av )
{
    if (check_input(ac) == false)
        return (1);
    std::string file = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::fstream inputFile;
    std::fstream outputFile;
    std::ofstream createFile((file + ".replace").c_str());
    createFile.close();
    outputFile.open((file + ".replace").c_str());
    outputFile.clear();
    inputFile.open(file.c_str());
    if (check_files(inputFile, outputFile) == false)
        return (1);
    change_the_line(inputFile, outputFile, s1, s2);
    inputFile.close();
    outputFile.close();
    return (0);
}
