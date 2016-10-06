//
// Created by vadim on 06.10.16.
//

#include <iostream>
#include "AbstractSyntaxTree.h"

bool ASTNode::getValue() {
    return content.value;
}

void ASTNode::setValue(bool value) {
    content.value = value;
}

char ASTNode::getOperatorSign() {
    return content.operatorSign;
}

void ASTNode::setOperatorSign(char operatorSign) {
    content.operatorSign = operatorSign;
}

ASTNode *ASTNode::createValueNode(bool value) {
    ASTNode *node = new ASTNode;
    node->type = VALUE;
    node->content.value = value;
    node->left = node->right = nullptr;
    return node;
}

ASTNode *ASTNode::createOrNode(ASTNode *left, ASTNode *right) {
    ASTNode *node = new ASTNode;
    node->type = OPERATOR;
    node->content.operatorSign = '|';
    node->left = left;
    node->right = right;
    return node;
}

ASTNode *ASTNode::createAndNode(ASTNode *left, ASTNode *right) {
    ASTNode *node = new ASTNode;
    node->type = OPERATOR;
    node->content.operatorSign = '&';
    node->left = left;
    node->right = right;
    return node;
}

ASTNode *ASTNode::createNotNode(ASTNode *left) {
    ASTNode *node = new ASTNode;
    node->type = OPERATOR;
    node->content.operatorSign = '!';
    node->left = left;
    node->right = nullptr;
    return node;
}

ASTNode *ASTNode::createAssignmentNode(ASTNode *left) {
    ASTNode *node = new ASTNode;
    node->type = OPERATOR;
    node->content.operatorSign = '=';
    node->left = left;
    node->right = nullptr;
    return node;
}

ASTNode *ASTNode::createVariableNode() {
    ASTNode *node = new ASTNode;
    node->type = VARIABLE;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

ASTNode::~ASTNode() {
    delete left;
    delete right;
}

AbstractSyntaxTree::~AbstractSyntaxTree() {
    delete root;
}
