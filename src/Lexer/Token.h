//
//  Token.hpp
//  PoopProject
//
//  Created by Michael Steijlen on 5/9/21.
//
#include <string>
#include <vector>

class Token
{
public:
    enum ETag
    {
        AND,BASIC, BREAK, DO, ELSE,
        EQ,FALZO,GE,ID,IF,
        INDEX,LE,MINUS,NE,NUM,
        OR,REAL,TEMP,TRUSKI,WHILE
        
    };
    
    static std::vector<std::string> tagStrings;
    
    int tag;
    Token(int t) {tag = t;};

    virtual std::string getString();
};

class Num : public Token
{
public:
    int value;
    Num(int v) : Token(ETag::NUM) { this->value = v; };
    std::string getString() override;
    
};

class Real : public Token
{
public:

    float value;
    Real(float v) : Token(ETag::REAL) { this->value = v; };
    std::string getString() override;
};

class Word : public Token
{
public:
    std::string lexeme;
    Word(std::string s, int tag ) : Token(tag) { this->lexeme = s; };
    std::string getString() override;
    
    static Word andd;
    static Word orr;
    static Word eq;
    static Word ne;
    static Word le;
    static Word ge;
    static Word minus;
    static Word True;
    static Word False;
    static Word temp;
    
    
};


