//
//  Lexer.h
//  PoopProject
//
//  Created by Michael Steijlen on 5/9/21.
//

#include <string>
#include <fstream>

class Lexer
{
public:
    std::string filePath;
    std::basic_ifstream<char> inputFileStream;
    Lexer(std::string filePath);
    ~Lexer();
    
    void scanFile();
    
};
