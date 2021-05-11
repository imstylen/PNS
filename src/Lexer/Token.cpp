//
//  Token.cpp
//  PoopProject
//
//  Created by Michael Steijlen on 5/9/21.
//
#pragma once

#include "Token.h"

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
	return std::to_string(tag);
}
