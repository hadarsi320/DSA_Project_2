//
// Created by Hadar on 18-Jan-20.
//

#ifndef DSA_PROJECT_2_DYNAMIC_GRAPH_H
#define DSA_PROJECT_2_DYNAMIC_GRAPH_H


#include "Graph_Node.h"
#include "Graph_Edge.h"

class Dynamic_Graph {
private:
    Graph_Node *_firstGraphNode;
    Graph_Edge *_firstGraphEdge;

public:
    Dynamic_Graph();

    ~Dynamic_Graph();

    Graph_Node* Insert_Node(unsigned node_key);

    void Delete_Node(Graph_Node* node);

    Graph_Edge* Insert_Edge(Graph_Node* from, Graph_Node* to);

    void Delete_Edge(Graph_Edge* edge);
};


#endif //DSA_PROJECT_2_DYNAMIC_GRAPH_H