#include "Log.h"
#include <string>
#include <fstream>

#include "Lexer.h"
int main(int argc, char* argv[])
{
    
    std::string line;
    Lexer lexer("src.pns");
    lexer.scanFile();
    
    
    return 0;
}
