//
// Created by Saksham Sachdev on 2016-09-08.
//

#include <iostream>
#include <vector>
#include "Lexer.h"
#include <regex>

using namespace std;

namespace {
    string regexEscape(string word) {
        return "";
    }
}

Lexer::Lexer(std::string input) : input(input), chunk(input) {
    int i = 0, bytesConsumed = 0;

    while(i < input.length()) {
        chunk = input.substr(i);
        std::cout << chunk << std::endl;
        i++;
    }
}

boost::container::vector<Token> Lexer::getTokens() {
    return tokens;
}

/**
 * Matching functions:
 */

/**
 * actual word tokenizer. Does a regex match on the keyword against current chunk being observed
 * @param name of token to tokenize
 * @param word actual token
 * @return
 */
int Lexer::tokenizeFromWord(const std::string name, std::string word = name) {
    return 0;
}

/**
 * Tokenizes from a set of given possible keywords (listed as member const vectors of strings)
 * @param name of token
 * @param list corresponding const vector of strings
 * @return
 */
int Lexer::tokenizeFromList(const std::string name, const std::vector<std::string> list) {
    return 0;
}

/**
 * Tokenize functions
 */

int Lexer::keywordToken() {
    return tokenizeFromWord("SELECT") ||
           tokenizeFromWord("DISTINCT") ||
           tokenizeFromWord("FROM") ||
           tokenizeFromWord("WHERE") ||
           tokenizeFromWord("GROUP") ||
           tokenizeFromWord("ORDER") ||
           tokenizeFromWord("BY") ||
           tokenizeFromWord("HAVING") ||
           tokenizeFromWord("LIMIT") ||
           tokenizeFromWord("JOIN") ||
           tokenizeFromWord("LEFT") ||
           tokenizeFromWord("RIGHT") ||
           tokenizeFromWord("INNER") ||
           tokenizeFromWord("OUTER") ||
           tokenizeFromWord("ON") ||
           tokenizeFromWord("AS") ||
           tokenizeFromWord("UNION") ||
           tokenizeFromWord("ALL") ||
           tokenizeFromWord("LIMIT") ||
           tokenizeFromWord("OFFSET") ||
           tokenizeFromWord("FETCH") ||
           tokenizeFromWord("ROW") ||
           tokenizeFromWord("ROWS") ||
           tokenizeFromWord("ONLY") ||
           tokenizeFromWord("NEXT") ||
           tokenizeFromWord("FIRST");
}

int Lexer::dotToken() {
    return tokenizeFromWord("DOT", ".");
}

int Lexer::operatorToken() {
    return tokenizeFromList("OPERATOR", SQL_OPERATORS);
}

int Lexer::mathToken() {
    return tokenizeFromList("MATH", MATH) || tokenizeFromList("MATH_MULTI", MATH_MULTI);
}

int Lexer::conditionalToken() {
    return tokenizeFromList("CONDITIONAL", SQL_CONDITIONALS);
}

int Lexer::betweendToken() {
    return tokenizeFromList("BETWEEN", SQL_BETWEENS);
}

int Lexer::subSelectOpToken() {
    return tokenizeFromList("SUB_SELECT_OP", SUB_SELECT_OP);
}

int Lexer::subSelectUnaryOpToken() {
    return tokenizeFromList("SUB_SELECT_UNARY_OP", SUB_SELECT_UNARY_OP);
}

int Lexer::functionToken() {
    return tokenizeFromList("FUNCTION", SQL_FUNCTIONS);
}

int Lexer::sortOrderToken() {
    return tokenizeFromList("DIRECTION", SQL_SORT_ORDERS);
}

int Lexer::booleanToken() {
    return tokenizeFromList("BOOLEAN", BOOLEAN);
}

