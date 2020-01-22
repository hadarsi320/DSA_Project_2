//
// Created by Hadar on 18-Jan-20.
//

#ifndef DSA_PROJECT_2_GRAPH_EDGE_H
#define DSA_PROJECT_2_GRAPH_EDGE_H


#include "Graph_Node.h"

class Graph_Edge {
private:
    Graph_Node *_src;
    Graph_Node *_dest;
    ListItem<Graph_Node> *_destInSrc; //Points to the relevant list node in the src graph node's out adjacency list
    ListItem<Graph_Node> *_srcInDest; //Points to the relevant list node in the dst graph node's in adjacency list
    Graph_Edge *_nextEdge;
    Graph_Edge *_prevEdge;

public:
    Graph_Edge(Graph_Node *src, Graph_Node *dest);

    ~Graph_Edge();

    Graph_Node *getSrc() const;

    Graph_Node *getDest() const;

    ListItem<Graph_Node> *getDestInSrc() const;

    ListItem<Graph_Node> *getSrcInDest() const;

    Graph_Edge *getNextEdge() const;

    Graph_Edge *getPrevEdge() const;

    void setNextEdge(Graph_Edge *nextEdge);

    void setPrevEdge(Graph_Edge *prevEdge);

    void transposeEdge();
};


#endif //DSA_PROJECT_2_GRAPH_EDGE_H
