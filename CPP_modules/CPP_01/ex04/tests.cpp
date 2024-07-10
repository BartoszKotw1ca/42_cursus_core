#include <cassert>
#include "main.hpp"

void test_check_input() {
    if (!(check_input(4) == true))
    {
        std::cout << "!" << std::endl;
        exit (1);
    }

    if (!(check_input(3) == false))
    {
        std::cout << "!" << std::endl;
        exit (1);
    }
}

void test_check_files() {
    std::string filename = "test.txt";
    std::ofstream testFile(filename.c_str());
    testFile.close();

    std::fstream inputFile(filename.c_str());
    std::string outputFilename = "test.replace";
    std::fstream outputFile(outputFilename.c_str(), std::ios::out);
    if (!(check_files(inputFile, outputFile) == true))
    {
        std::cout << "!" << std::endl;
        exit (1);
    }

    std::string nonExistingFilename = "non_existing.txt";
    std::fstream nonExistingFile(nonExistingFilename.c_str());
    if (!(check_files(nonExistingFile, outputFile) == false))
    {
        std::cout << "!" << std::endl;
        exit (1);
    }

    std::remove(filename.c_str());
    std::remove(outputFilename.c_str());
}

void test_change_the_line() {
    std::string inputFileStr = "test.txt";
    std::ofstream testFile(inputFileStr.c_str());
    testFile << "Hello world\n";
    testFile << "Goodbye world\n";
    testFile.close();

    std::fstream inputFile(inputFileStr.c_str());
    std::string outputFileStr = "test.replace";
    std::fstream outputFile(outputFileStr.c_str(), std::ios::out);
    std::string s1 = "world";
    std::string s2 = "Earth";

    change_the_line(inputFile, outputFile, s1, s2);

    inputFile.close();
    outputFile.close();

    std::ifstream checkFile(outputFileStr.c_str());
    std::string line;

    std::getline(checkFile, line);
    assert(line == "Hello Earth");

    std::getline(checkFile, line);
    assert(line == "Goodbye Earth");

    checkFile.close();

    std::remove(inputFileStr.c_str());
    std::remove(outputFileStr.c_str());
}

int main() {
    test_check_input();
    test_check_files();
    test_change_the_line();
    std::cout << "Passed!!!" << std::endl;
    return 0;
}
