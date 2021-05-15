//
//  Token.cpp
//  PoopProject
//
//  Created by Michael Steijlen on 5/9/21.
//
#include "Token.h"
#include <iostream>
std::vector<std::string> Token::tagStrings
{
        std::string("AND"),
        std::string("BASIC"),
        std::string("BREAK"),
        std::string("DO"),
        std::string("ELSE"),
        std::string("EQ"),
        std::string("FALZO"),
        std::string("GE"),
        std::string("ID"),
        std::string("IF"),
        std::string("INDEX"),
        std::string("LE"),
        std::string("MINUS"),
        std::string("NE"),
        std::string("NUM"),
        std::string("OR"),
        std::string("REAL"),
        std::string("TEMP"),
        std::string("TRUSKI"),
        std::string("WHILE"),
};

//Initialize static variables.
Word Word::andd = Word("&&", ETag::AND);
Word Word::orr = Word("||", ETag::OR);
Word Word::eq = Word("==", ETag::EQ);
Word Word::ne = Word("!=", ETag::NE);
Word Word::le = Word("<=", ETag::LE);
Word Word::ge = Word(">=", ETag::GE);
Word Word::minus = Word("minus", ETag::MINUS);
Word Word::True = Word("true", ETag::TRUSKI);
Word Word::False = Word("false", ETag::FALZO);
Word Word::temp = Word("t", ETag::TEMP);

std::string Token::getString()
{
    std::string v = "";
    if(this->tag < tagStrings.size())
    {
        v =Token::tagStrings[this->tag];
    }
    else
    {
        v += (char) this->tag;
    }
    std::string s = std::string("Tok ( ") + v + std::string(" )");
	return s;
}

std::string Num::getString()
{
    std::string s = std::string("Tok ( ") + Token::tagStrings[this->tag] + std::string(", ")+ std::to_string(this->value) + std::string(" )");
    return s;
}

std::string Real::getString()
{
    std::string s = std::string("Tok ( ") + Token::tagStrings[this->tag] + std::string(", ") + std::to_string(this->value) + std::string(" )");
    
    return s;
}

std::string Word::getString()
{
    std::string s = std::string("Tok ( ") + Token::tagStrings[this->tag] + std::string(", ")+ this->lexeme + std::string(" )");
    return s;
}
