//
// Created by vadim on 06.10.16.
//

#ifndef LAB27_LEXER_H
#define LAB27_LEXER_H


class Lexer {
    const char *input, *current;
    void skipWhitespace();
public:
    Lexer(const char *input): input(input), current(input) {};
    char getCurrentToken();
    bool nextToken();

};


#endif //LAB27_LEXER_H
