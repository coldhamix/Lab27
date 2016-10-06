//
// Created by vadim on 07.10.16.
//

#include "Interpreter.h"

bool Interpreter::executeNode(ASTNode *node) {
    if (node == nullptr)
        return 0;

    bool leftValue = executeNode(node->left);
    bool rightValue = executeNode(node->right);

    if (node->type == VALUE)
        return node->content.value; // no need in left & right side zeros

    if (node->type == VARIABLE)
        return x;


    switch (node->content.operatorSign) {
        case '&':
            return leftValue & rightValue;
        case '|':
            return leftValue | rightValue;
        case '!':
            return !leftValue;
        case '=':
            return x = leftValue;
    }
};

bool Interpreter::execute(const char *input) {
    AbstractSyntaxTree *tree = parser.execute(input);
    return executeNode(tree->root);
};
