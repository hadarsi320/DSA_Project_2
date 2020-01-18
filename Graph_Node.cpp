//
// Created by Hadar on 18-Jan-20.
//

#include "Graph_Node.h"

Graph_Node::Graph_Node(unsigned int key) :
_key(key), _inAdjacencyList(), _outAdjacencyList(), _nextNode(NULL), _prevNode(NULL) {}

Graph_Node *Graph_Node::getNextNode() const {
    return _nextNode;
}

void Graph_Node::setNextNode(Graph_Node *nextNode) {
    _nextNode = nextNode;
}

Graph_Node *Graph_Node::getPrevNode() const {
    return _prevNode;
}

void Graph_Node::setPrevNode(Graph_Node *prevNode) {
    _prevNode = prevNode;
}

unsigned int Graph_Node::getKey() const {
    return _key;
}


