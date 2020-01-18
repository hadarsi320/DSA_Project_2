//
// Created by Hadar on 18-Jan-20.
//

#ifndef DSA_PROJECT_2_GRAPH_NODE_H
#define DSA_PROJECT_2_GRAPH_NODE_H


#include "List.h"

class Graph_Node {
private:
    List<Graph_Node> _inAdjacencyList;
    List<Graph_Node> _outAdjacencyList;
    Graph_Node *_nextNode;
    Graph_Node *_prevNode;
    unsigned _key;

public:
    Graph_Node(unsigned int key);

    virtual ~Graph_Node() {}

    unsigned Get_out_Degree() const
    {
        return _outAdjacencyList.length();
    }

    unsigned Get_in_Degree() const
    {
        return _inAdjacencyList.length();
    }

    unsigned Get_key() const
    {
        return _key;
    }

    Graph_Node *getNextNode() const;

    void setNextNode(Graph_Node *nextNode);

    Graph_Node *getPrevNode() const;

    void setPrevNode(Graph_Node *prevNode);

    unsigned int getKey() const;

    void addInNeighbour(Graph_Node * inNeighbour);

    void addOutNeighbour(Graph_Node * outNeighbour);

};


#endif //DSA_PROJECT_2_GRAPH_NODE_H