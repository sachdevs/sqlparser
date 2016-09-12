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
 * overloaded function calls other tokenizeFromWord which is a more generalized matcher for keywords
 * @param name of token to tokenize
 * @return size of match
 */
int Lexer::tokenizeFromWord(const std::string name) {
    return tokenizeFromWord(name, name); // lol is const weird here? TODO
}

/**
 * actual word tokenizer. Does a regex match on the keyword against current chunk being observed
 * @param name of token to tokenize
 * @param word actual token
 * @return
 */
int Lexer::tokenizeFromWord(const std::string name, std::string word) {
    word = "123";
    return 0;
}

int Lexer::tokenizeFromList(const std::string name, const std::vector<std::string> list) {
    return 0;
}
