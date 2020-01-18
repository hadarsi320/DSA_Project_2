//
// Created by eldar.a on 17/01/2020.
//

#ifndef DS_A_ROOTED_TREE_H
#define DS_A_ROOTED_TREE_H

#include <cstddef>
#include <ostream>
#include "Queue.h"
#include "Tree_Node.h"

class Rooted_Tree {
private:
    Tree_Node * _root;

public:
    Rooted_Tree() : _root(NULL) {}

    ~Rooted_Tree();

    Tree_Node *getRoot() const {
        return _root;
    }

    void setRoot(Tree_Node *root) {
        if (root->getRightSibling() != NULL) {
            throw "Trying to set a root with sibling!";
        }
        _root = root;
    }

    void Print_By_Layer(std::ostream& stream) const;

    void Preorder_Print(std::ostream& stream) const;
};

#endif //DS_A_ROOTED_TREE_H
