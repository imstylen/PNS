//
//  Lexer.h
//  PoopProject
//
//  Created by Michael Steijlen on 5/9/21.
//

#include <string>
#include <fstream>
#include <map>
#include "Token.h"
#include <vector>

class Lexer
{
public:

    Lexer(std::string filePath);
    ~Lexer();
    
	std::string filePath;
	std::basic_ifstream<char> inputFileStream;

    int line = 1;
    char peek = ' ';
        
    std::map<std::string, Word> reservedWords;

    void reserve(Word w) { reservedWords.insert(std::pair<std::string, Word>(w.lexeme, w)); };

    void readch();
    bool readch(char c);

    //TODO this slices word objects dumb dubm.
    //Allocate on heap instead using new keyword.
    //This variable will becom an array of Token pointers.
    std::vector<Token*> tokens;

    Token* scan();



    void scanFile();
    
};
