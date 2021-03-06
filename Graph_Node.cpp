//
// Created by Hadar on 18-Jan-20.
//

#include "Graph_Node.h"

Graph_Node::Graph_Node(unsigned int key) :
        _key(key), _inAdjacencyList(), _outAdjacencyList(), _nextNode(NULL), _prevNode(NULL), color(NOCOLOR) {}

Graph_Node::~Graph_Node() {}

unsigned Graph_Node::Get_key() const {
    return _key;
}

unsigned Graph_Node::Get_in_Degree() const {
    return _inAdjacencyList.length();
}

unsigned Graph_Node::Get_out_Degree() const {
    return _outAdjacencyList.length();
}

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

ListItem<Graph_Node> * Graph_Node::addInNeighbour(Graph_Node *inNeighbour) {
    _inAdjacencyList.insert(inNeighbour);
    return _inAdjacencyList.getHead();
}

ListItem<Graph_Node> * Graph_Node::addOutNeighbour(Graph_Node *outNeighbour) {
    _outAdjacencyList.insert(outNeighbour);
    return _outAdjacencyList.getHead();
}

void Graph_Node::removeInNeighbour(ListItem<Graph_Node> *neighbour)
{
    _inAdjacencyList.remove(neighbour);
}

void Graph_Node::removeOutNeighbour(ListItem<Graph_Node> *neighbour)
{
    _outAdjacencyList.remove(neighbour);
}

ListItem<Graph_Node> *Graph_Node::getFirstInNeighbour() {
    return _inAdjacencyList.getHead();
}

ListItem<Graph_Node> *Graph_Node::getFirstOutNeighbour() {
    return _outAdjacencyList.getHead();
}

void Graph_Node::transposeNode()
{
    _outAdjacencyList.swapLists(_inAdjacencyList);
}



