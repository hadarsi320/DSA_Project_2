//
// Created by eldar.a on 17/01/2020.
//

#include "Rooted_Tree.h"

Rooted_Tree::~Rooted_Tree() {
    delete _root;
}

void Rooted_Tree::Print_By_Layer(std::ostream &stream) const {
    Queue<Tree_Node> queue;
    Tree_Node *x = _root;
    Tree_Node *newLayerPtr = NULL;
    while (x != NULL or !queue.isEmpty()) {
        if (x == NULL) {
            x = queue.dequeue();
        }
        if (newLayerPtr == NULL) {
            newLayerPtr = x->getLeftChild();
        }
        if (newLayerPtr == x) {
            stream << "\n";
            newLayerPtr = x->getLeftChild();
        }
        else {
            if (x != _root)
                stream << ",";
        }
        stream << x->getKey();
        if (x->getLeftChild() != NULL) {
            queue.enqueue(x->getLeftChild());
        }
        x = x->getRightSibling();
    }
}

void Rooted_Tree::Preorder_Print(std::ostream &stream) const {
    if (_root == NULL) {
        stream << "TREE IS EMPTY!";
        return;
    }
    preorderPrintNode(stream, _root);
}

void Rooted_Tree::preorderPrintNode(std::ostream &stream, Tree_Node *currentNode) const {
    if (currentNode == NULL)
        return;
    stream << currentNode->getKey() << ",";
    preorderPrintNode(stream, currentNode->getLeftChild());
    preorderPrintNode(stream, currentNode->getRightSibling());
}
