//
// Created by Hadar on 18-Jan-20.
//

#include "Graph_Edge.h"

Graph_Edge::Graph_Edge(Graph_Node *src, Graph_Node *dest) :
        _src(src), _dest(dest), _destInSrc(_src->addOutNeighbour(_dest)), _srcInDest(_dest->addInNeighbour(_src)), _nextEdge(NULL), _prevEdge(NULL) {
//    _srcInDest = _dest->addInNeighbour(_src);
//    _destInSrc = _src->addOutNeighbour(_dest);
}

Graph_Edge::~Graph_Edge()
{
    _src->removeOutNeighbour(_srcInDest);
    _dest->removeInNeighbour(_destInSrc);
}

Graph_Node *Graph_Edge::getSrc() const {
    return _src;
}

Graph_Node *Graph_Edge::getDest() const {
    return _dest;
}

ListItem<Graph_Node> *Graph_Edge::getDestInSrc() const {
    return _destInSrc;
}

ListItem<Graph_Node> *Graph_Edge::getSrcInDest() const {
    return _srcInDest;
}

Graph_Edge *Graph_Edge::getNextEdge() const {
    return _nextEdge;
}

Graph_Edge *Graph_Edge::getPrevEdge() const {
    return _prevEdge;
}

void Graph_Edge::setNextEdge(Graph_Edge *nextEdge) {
    _nextEdge = nextEdge;
}

void Graph_Edge::setPrevEdge(Graph_Edge *prevEdge) {
    _prevEdge = prevEdge;
}

void Graph_Edge::transposeEdge()
{
    Graph_Node *tmpNode = _src;
    _src = _dest;
    _dest = tmpNode;

    ListItem<Graph_Node> *tmpItem = _destInSrc;
    _destInSrc = _srcInDest;
    _srcInDest = tmpItem;
}
