//
// Created by Saksham Sachdev on 2016-09-08.
//

#ifndef SQLPARSER_LEXER_H
#define SQLPARSER_LEXER_H

#include <string>

#include <boost/container/vector.hpp>

typedef std::pair<std::string, std::string> Token;

class Lexer {
public:
    Lexer(std::string input);
    boost::container::vector<Token> getTokens();

private:
    boost::container::vector<Token> tokens;
    std::string input;
    std::string chunk;
};


#endif //SQLPARSER_LEXER_H