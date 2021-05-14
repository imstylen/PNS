//
//  Lexer.cpp
//  PoopProject
//
//  Created by Michael Steijlen on 5/9/21.
//
#include "Log.h"
#include "Lexer.h"
#include <ctype.h>
Lexer::Lexer(std::string filePath)
{
    PNS_LOG("Lexer object created!");
    this->filePath = filePath;
    inputFileStream = std::ifstream(filePath);

    //Reserve words:
    Lexer::reserve(Word("if", Token::ETag::IF));
    Lexer::reserve(Word("else", Token::ETag::ELSE));
    Lexer::reserve(Word("while", Token::ETag::WHILE));
    Lexer::reserve(Word("do", Token::ETag::IF));
    Lexer::reserve(Word("break", Token::ETag::IF));
	Lexer::reserve(Word::True);
	Lexer::reserve(Word::False);

    //TODO: Reserve words from class Type. Subclass of Word.

}

void Lexer::readch()
{
    this->peek = inputFileStream.get();

}

bool Lexer::readch(char c)
{
    readch();

    if (this->peek != c)
    {
        return false;
    }
    else
    {
		this->peek = ' ';
        return true;
    }

}


Token* Lexer::scan()
{
    while (true)
    {
        readch();
        if (peek == ' ' || peek == '\t')
        {
            continue;
        }
        else if (peek == '\n')
        {
            line = line + 1;
        }
        else
        {
            break;
        }
    }

    PNS_LOG(std::string("peek: ")+= peek);
    
    switch (peek)
    {
    case '\377':
            return nullptr;
            break;
    case '&':
        if (readch('&'))
        {
            tokens.push_back(&Word::andd);
            return tokens.back();
            break;
        }
        else
        {
            tokens.push_back(new Token('&'));
            return tokens.back();
            break;
        }
	case '|':
		if (readch('|'))
		{
			tokens.push_back(&Word::orr);
			return tokens.back();
			break;
		}
		else
		{
			tokens.push_back(new Token('|'));
			return tokens.back();
			break;
		}
	case '=':
		if (readch('='))
		{
			tokens.push_back(&Word::eq);
			return tokens.back();
			break;
		}
		else
		{
			tokens.push_back(new Token('='));
			return tokens.back();
			break;
		}
	case '!':
		if (readch('='))
		{
			tokens.push_back(&Word::ne);
			return tokens.back();
			break;
		}
		else
		{
			tokens.push_back(new Token('!'));
			return tokens.back();
			break;
		}
	case '<':
		if (readch('='))
		{
			tokens.push_back(&Word::le);
			return tokens.back();
			break;
		}
		else
		{
			tokens.push_back(new Token('<'));
			return tokens.back();
			break;
		}
	case '>':
		if (readch('='))
		{
			tokens.push_back(&Word::ge);
			return tokens.back();
			break;
		}
		else
		{
			tokens.push_back(new Token('>'));
			return tokens.back();
			break;
		}
    }


	if (isdigit(peek))
	{
		//Could be a float.
		int v = 0;
		while (isdigit(peek))
		{
			v = 10 * v + (int)peek;
			readch();
		}
		if (peek != '.')
		{
			tokens.push_back(new Num(v));
			return tokens.back();
		}

		//Number is a float.
		float x = (float)v;

		float d = 10.f;

		while (true)
		{
			//Move on from the '.'
			readch();

			if (!isdigit(peek))
			{
				break;
			}
			else
			{
				x = x + (float)peek / d;
				d = d * 10;
			}

			tokens.push_back(new Real(x));
		}
	}

	if (isalpha(peek))
	{
		std::string stringBuffer = "";

		while (isalpha(peek))
		{
			stringBuffer += peek;
			readch();
		}

		//Check our reserved words for the word we just found.
        Word* foundWord;
        try{
            foundWord = &reservedWords.at(stringBuffer);
        }
        catch (std::out_of_range)
        {
            foundWord = nullptr;
        }
        
        if (foundWord != nullptr)
		{
			tokens.push_back(foundWord);
			return tokens.back();
		}
		else
		{
			//New word.
			tokens.push_back(new Word(stringBuffer, Token::ETag::ID));
            
			return tokens.back();
		}

	}

	tokens.push_back(new Token(peek));
	return tokens.back();

}

void Lexer::scanFile()
{
	Token* newToken = nullptr;

	while (true)
	{
		newToken = scan();

        Word* newWord = (Word*) newToken;
        if (newWord != nullptr)
        {
            PNS_LOG(newWord->lexeme);
        }
        
        if(newToken == nullptr)
        {
            break;
        }

	}

}

Lexer::~Lexer()
{
    PNS_LOG("Lexer has been deleted");
    for(Token* t : tokens)
    {
        PNS_LOG("Deleting :" + t->getString());
        delete t;
    }
    inputFileStream.close();
}
