//
// Created by Saksham Sachdev on 2016-09-08.
//

#ifndef SQLPARSER_LEXER_H
#define SQLPARSER_LEXER_H

#include <string>

#include <boost/container/vector.hpp>
#include <regex>

/*
 * Token:
 *      first->name: refers to name of token. I.e DOT for '.' token.
 *      second->value/word: actual value for token. I.e '.' for DOT token.
 */
typedef std::pair<std::string, std::string> Token;

class Lexer {
public:
    Lexer(std::string input);
    boost::container::vector<Token> getTokens();

private:
    boost::container::vector<Token> tokens;
    std::string input;
    std::string chunk;

    void addToken(const Token t);

    // keyword vectors
    const std::vector<std::string> SQL_FUNCTIONS{"AVG", "COUNT", "MIN", "MAX", "SUM"};
    const std::vector<std::string> SQL_SORT_ORDERS{"ASC", "DESC"};
    const std::vector<std::string> SQL_OPERATORS{"=", "!=", ">=", ">", "<=", "<>", "<", "LIKE", "IS NOT", "IS"};
    const std::vector<std::string> SUB_SELECT_OP{"IN", "NOT IN", "ANY", "ALL", "SOME"};
    const std::vector<std::string> SUB_SELECT_UNARY_OP{"EXISTS"};
    const std::vector<std::string> SQL_CONDITIONALS{"AND", "OR"};
    const std::vector<std::string> SQL_BETWEENS{"BETWEEN", "NOT BETWEEN"};
    const std::vector<std::string> BOOLEAN{"TRUE", "FALSE", "NULL"};
    const std::vector<std::string> MATH{"+", "-"};
    const std::vector<std::string> MATH_MULTI{"/", "*"};

    // regex based matching
//    STAR
//    SEPARATOR
//    WHITESPACE
//    LITERAL
//    PARAMETER
//    NUMBER
//    STRING
//    DBLSTRING


//    int tokenizeFromWord(const std::string name);
    int tokenizeFromWord(const std::string name, std::string word);
    // TODO implement
    int tokenizeFromRegex(const std::string name, std::regex reg, int part = 0, int lengthPart = part, bool output = true);
    int tokenizeFromList(const std::string name, const std::vector<std::string> list);

    // matching functions
    int keywordToken();
    int dotToken();
    int operatorToken();
    int mathToken();
    int conditionalToken();
    int betweendToken();
    int subSelectOpToken();
    int subSelectUnaryOpToken();
    int functionToken();
    int sortOrderToken();
    int booleanToken();

    // regex matching functions TODO

};


#endif //SQLPARSER_LEXER_H