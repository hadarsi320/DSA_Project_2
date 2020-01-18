//
// Created by Hadar on 18-Jan-20.
//

#ifndef DSA_PROJECT_2_DYNAMIC_GRAPH_H
#define DSA_PROJECT_2_DYNAMIC_GRAPH_H


#include "Graph_Node.h"
#include "Graph_Edge.h"
#include "Rooted_Tree.h"
#include "Pair.h"

typedef Pair<Graph_Node, Tree_Node> BfsPair;

class Dynamic_Graph {
private:
    Graph_Node *_firstGraphNode;
    Graph_Edge *_firstGraphEdge;

    void BFS_Initialization(Graph_Node *s, Queue<BfsPair> *queue, Rooted_Tree *bfsTree) const;

public:
    Dynamic_Graph();

    ~Dynamic_Graph();

    Graph_Node* Insert_Node(unsigned node_key);

    void Delete_Node(Graph_Node* node);

    Graph_Edge* Insert_Edge(Graph_Node* from, Graph_Node* to);

    void Delete_Edge(Graph_Edge* edge);

    Rooted_Tree *BFS(Graph_Node *source) const;
};


#endif //DSA_PROJECT_2_DYNAMIC_GRAPH_H
