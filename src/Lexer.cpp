//
//  Lexer.cpp
//  PoopProject
//
//  Created by Michael Steijlen on 5/9/21.
//
#include "Log.h"
#include "Lexer.h"

Lexer::Lexer(std::string filePath)
{
    PNS_LOG("Lexer object created!");
    this->filePath = filePath;
    inputFileStream = std::ifstream(filePath);
}

void Lexer::scanFile()
{
    
    char c;
    if (inputFileStream.is_open())
    {
      while ( (c = inputFileStream.get()) != '\377' )
      {
          PNS_LOG(c);
      }
    } else PNS_LOG("Couldn't open file.");

}

Lexer::~Lexer()
{
    PNS_LOG("Lexer has been deleted");
    inputFileStream.close();
}
