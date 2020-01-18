//
// Created by eldar.a on 17/01/2020.
//

#ifndef DS_A_TREE_NODE_H
#define DS_A_TREE_NODE_H

#include <cstddef>

class Tree_Node {
private:
    unsigned int _key;
    Tree_Node * _parent;
    Tree_Node * _leftChild;
    Tree_Node * _rightSibling;

public:
    Tree_Node(unsigned int key=0, Tree_Node *parent=NULL, Tree_Node *leftChild=NULL, Tree_Node *rightSibling=NULL) :
            _key(key), _parent(parent), _leftChild(leftChild), _rightSibling(rightSibling) {}

    ~Tree_Node() {
        delete _leftChild;
        delete _rightSibling;
    }

    unsigned int getKey() const {
        return _key;
    }

    Tree_Node *getParent() const {
        return _parent;
    }

    Tree_Node *getLeftChild() const {
        return _leftChild;
    }

    Tree_Node *getRightSibling() const {
        return _rightSibling;
    }

    void setKey(unsigned int key) {
        _key = key;
    }

    void setParent(Tree_Node *parent) {
        _parent = parent;
    }

    void setLeftChild(Tree_Node *leftChild) {
        _leftChild = leftChild;
    }

    void setRightSibling(Tree_Node *rightSibling) {
        _rightSibling = rightSibling;
    }

};

#endif //DS_A_TREE_NODE_H
