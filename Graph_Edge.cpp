//
// Created by Hadar on 18-Jan-20.
//

#include "Graph_Edge.h"

const Graph_Node *Graph_Edge::getSrc() const {
    return _src;
}

const Graph_Node *Graph_Edge::getDest() const {
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

Graph_Edge::Graph_Edge(Graph_Node *src, Graph_Node *dest) :
_src(src), _dest(dest), _destInSrc(NULL), _srcInDest(NULL), _nextEdge(NULL), _prevEdge(NULL) {
    _destInSrc = _src->addOutNeighbour(_dest);
    _srcInDest = _dest->addInNeighbour(_src);
}
