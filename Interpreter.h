//
// Created by vadim on 07.10.16.
//

#ifndef LAB27_EXECUTINGCONTEXT_H
#define LAB27_EXECUTINGCONTEXT_H


#include "Parser.h"

class Interpreter {
    Parser parser;
    bool x;

    bool executeNode(ASTNode *node);
public:
    Interpreter(): x(false) {}
    bool execute(const char*);
};


#endif //LAB27_EXECUTINGCONTEXT_H
