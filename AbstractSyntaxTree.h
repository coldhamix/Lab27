//
// Created by vadim on 06.10.16.
//

#ifndef LAB27_ABSTRACTSYNTAXTREE_H
#define LAB27_ABSTRACTSYNTAXTREE_H


enum ASTNodeType {
    VALUE, VARIABLE, OPERATOR
};

class ASTNode {
    friend class AbstractSyntaxTree;
    friend class Interpreter;

    ASTNodeType type;
    union {
        bool value;
        char operatorSign;
    } content;

    ASTNode *left, *right;
public:
    bool getValue();
    void setValue(bool);

    char getOperatorSign();
    void setOperatorSign(char);

    ~ASTNode();

    /*
     * FACTORY METHODS
     */
    static ASTNode *createVariableNode();
    static ASTNode *createValueNode(bool);
    static ASTNode *createOrNode(ASTNode*, ASTNode*);
    static ASTNode *createAndNode(ASTNode*, ASTNode*);
    static ASTNode *createNotNode(ASTNode*);
    static ASTNode *createAssignmentNode(ASTNode*);
};



class AbstractSyntaxTree {
    friend class Interpreter;
    ASTNode *root;
public:
    AbstractSyntaxTree(ASTNode* root): root(root) {}
    ~AbstractSyntaxTree();
};


#endif //LAB27_ABSTRACTSYNTAXTREE_H
