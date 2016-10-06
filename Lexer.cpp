//
// Created by vadim on 06.10.16.
//

#include <cctype>
#include "Lexer.h"

void Lexer::skipWhitespace() {
    while (*current != '\0' && isspace(*current)) {
        ++current;
    }
}

char Lexer::getCurrentToken() {
    skipWhitespace();
    return *current;
}

bool Lexer::nextToken() {
    ++current;
    skipWhitespace();
    return *current != '\0';
}
