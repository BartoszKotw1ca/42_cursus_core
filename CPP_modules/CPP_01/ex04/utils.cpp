#include "main.hpp"

bool check_input( int ac )
{
    if (ac != 4)
    {
        errno = EINVAL;
        perror ("Wrong numbers of arguments!!!");
        return ( false );
    }
    return ( true );
}

bool check_files( std::fstream &inputFile, std::fstream &outputFile )
{
    if (inputFile.fail() || outputFile.fail())
    {
        std::cerr << "Unable to open file " << std::endl;
        return ( false );
    }
    return ( true );
}

void change_the_line( std::fstream &inputFile, std::fstream &outputFile,
    std::string &s1, std::string &s2)
{
    std::string line;
    while (std::getline(inputFile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outputFile << line << std::endl;
    }
}
