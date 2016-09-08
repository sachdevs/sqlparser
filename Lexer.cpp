//
// Created by Saksham Sachdev on 2016-09-08.
//

#include <iostream>
#include "Lexer.h"

using namespace std;

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
