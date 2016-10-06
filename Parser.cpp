//
// Created by vadim on 07.10.16.
//

#include "Parser.h"

ASTNode* Parser::parseExpression() {
    if (lexer.getCurrentToken() == '$') {
        return parseAssignment();
    } else {
        ASTNode *term1 = parseTerm();
        while (lexer.getCurrentToken() == '|') {
            lexer.nextToken(); // eat | operator
            ASTNode *term2 = parseTerm();
            term1 = ASTNode::createOrNode(term1, term2);
        }
        return term1;
    }
}

ASTNode* Parser::parseAssignment() {
    lexer.nextToken(); // eat $ sign
    assert(lexer.getCurrentToken() == 'x', "Variable name expected");
    lexer.nextToken(); // eat variable name
    assert(lexer.getCurrentToken() == '=', "Variable assignment expected");
    lexer.nextToken(); // eat = sign
    return ASTNode::createAssignmentNode(
            parseExpression()
    );
}

ASTNode* Parser::parseTerm() {
    ASTNode *factor1 = parseFactor();
    while (lexer.getCurrentToken() == '&') {
        lexer.nextToken(); // eat & operator
        ASTNode *factor2 = parseFactor();
        factor1 = ASTNode::createAndNode(factor1, factor2);
    }
    return factor1;
}

ASTNode* Parser::parseFactor() {
    if (lexer.getCurrentToken() == '(') {
        lexer.nextToken(); // eat ( parenthesis
        ASTNode *factor = parseExpression();
        assert(lexer.getCurrentToken() == ')', "Missing closing parenthesis");
        lexer.nextToken(); // eat ) parenthesis
        return factor;
    } else if (lexer.getCurrentToken() == '!') {
        lexer.nextToken(); // eat ! operator;
        return ASTNode::createNotNode(
                parseFactor()
        );
    } else {
        return parseIdentifier();
    }
}

ASTNode* Parser::parseIdentifier() {
    bool isValidIdentifier =
            lexer.getCurrentToken() == '0' ||
            lexer.getCurrentToken() == '1' ||
            lexer.getCurrentToken() == 'x';

    assert(isValidIdentifier, "Expected identifier");

    ASTNode *result;
    if (lexer.getCurrentToken() == 'x') {
        result = ASTNode::createVariableNode();
    } else {
        result = ASTNode::createValueNode(lexer.getCurrentToken() - '0');
    }

    lexer.nextToken();
    return result;
}

AbstractSyntaxTree *Parser::execute(const char *input) {
    lexer = Lexer(input);
    return new AbstractSyntaxTree(
            parseExpression()
    );
}

void Parser::assert(bool condition, const char *message) {
    if (!condition)
        throw message;
}

