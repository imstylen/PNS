//
//  Token.hpp
//  PoopProject
//
//  Created by Michael Steijlen on 5/9/21.
//

#include <string>


class Token
{
public:
    enum ETag
    {
        AND,BASIC, BREAK, DO, ELSE,
        EQ,FALSE,GE,ID,IF,
        INDEX,LE,MINUS,NE,NUM,
        OR,REAL,TEMP,TRUE,WHILE
        
    };
    int tag;
    Token(int t) {tag = t;};
};

class Num : Token
{
    int value;
    Num(int v) : Token(ETag::NUM) { this->value = v; };
    
};

class Real : Token
{
    float value;
    Real(float v) : Token(ETag::REAL) { this->value = v; };
    
};

class Word : Token
{
public:
    std::string lexeme;
    Word(std::string s, int tag ) : Token(tag) { this->lexeme = s; };
    
    
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

//Initialize static variables.
Word Word::andd = Word("&&",ETag::AND);
Word Word::orr = Word("||",ETag::OR);
Word Word::eq = Word("==",ETag::EQ);
Word Word::ne = Word("!=",ETag::NE);
Word Word::le = Word("<=",ETag::LE);
Word Word::ge = Word(">=",ETag::GE);
Word Word::minus = Word("minus",ETag::MINUS);
Word Word::True = Word("true",ETag::TRUE);
Word Word::False = Word("false",ETag::FALSE);
Word Word::temp = Word("t",ETag::TEMP);

