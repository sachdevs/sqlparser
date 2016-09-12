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
    word = "123";
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

int Lexer::keywordToken() {
    return 0;
}

int Lexer::dotToken() {
    return 0;
}

int Lexer::operatorToken() {
    return 0;
}

int Lexer::mathToken() {
    return 0;
}

int Lexer::conditionalToken() {
    return 0;
}

int Lexer::betweendToken() {
    return 0;
}

int Lexer::subSelectOpToken() {
    return 0;
}

int Lexer::subSelectUnaryOpToken() {
    return 0;
}

int Lexer::functionToken() {
    return 0;
}

int Lexer::sortOrderToken() {
    return 0;
}

int Lexer::booleanToken() {
    return 0;
}

