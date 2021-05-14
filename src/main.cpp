#include "Log.h"
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

#include "Lexer/Lexer.h"
int main(int argc, char* argv[])
{
    std::cout << std::filesystem::current_path() << std::endl;
    std::string line;
    Lexer lexer("src.pns");
    lexer.scanFile();

    return 0;
}
