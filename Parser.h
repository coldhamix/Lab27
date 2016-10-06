//
// Created by vadim on 07.10.16.
//

#ifndef LAB27_PARSER_H
#define LAB27_PARSER_H

#include "Lexer.h"
#include "AbstractSyntaxTree.h"

/*
 *  LOGICAL EXPRESSION PARSER GRAMMAR:
 *
 *  EXPRESSION ::= TERM [ | TERM ]* / ASSIGNMENT
 *  ASSIGNMENT ::= $x = EXPRESSION
 *  TERM ::= FACTOR [ & FACTOR ]*
 *  FACTOR ::= (EXPRESSION) / INTEGER / !FACTOR
 *  IDENTIFIER ::= [0, 1, x]
 */

class Parser {
    Lexer lexer = 0;
    bool xValue;

    ASTNode* parseExpression();
    ASTNode* parseAssignment();
    ASTNode* parseTerm();
    ASTNode* parseFactor();
    ASTNode* parseIdentifier();
    static void assert(bool, const char*);
public:
    Parser(): xValue(false) {}
    AbstractSyntaxTree *execute(const char*);
};


#endif //LAB27_PARSER_H
