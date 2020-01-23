//
// Created by Hadar on 18-Jan-20.
//

#ifndef DSA_PROJECT_2_DYNAMIC_GRAPH_H
#define DSA_PROJECT_2_DYNAMIC_GRAPH_H

#include "Graph_Node.h"
#include "Graph_Edge.h"
#include "Rooted_Tree.h"
#include "Pair.h"
#include "Stack.h"

typedef Pair<Graph_Node, Tree_Node> BfsPair;

class Dynamic_Graph {
private:
    Graph_Node *_firstGraphNode;
    Graph_Edge *_firstGraphEdge;

    /**
     * This function sets the color of all of the nodes to white.
     * This attribute is relevant to functions BFS, DFS, and generatePsi
     */
    void resetColors() const;

    /**
     * This function initializes all of the values required to run BFS on the graph.
     * The function is based on function with the same name from the lecture notes.
     * @param sourceNode the source node for the BFS tree
     * @param treeNodeQueue a queue to be used by BFS, where the source node is entered
     * @param bfsTree an empty tree that is to be made the BFS tree
     */
    void BFS_Initialization(Graph_Node *sourceNode, Queue<BfsPair> *treeNodeQueue, Rooted_Tree *bfsTree) const;

    /**
     * A function similar to DFS_
     * @param nodePtr
     * @param psiStack
     */
    void generatePsiVisit(Graph_Node *nodePtr, Stack<Graph_Node> *psiStack) const;

    Stack<Graph_Node> *generatePsi() const;

    Queue<Tree_Node> *DFS(Stack<Graph_Node> *psiStack) const;

    void DFSVisit(Graph_Node *currentGraphNode, Tree_Node *parentTreeNode) const;

    void transpose() const;

public:
    Dynamic_Graph();

    ~Dynamic_Graph();

    Graph_Node* Insert_Node(unsigned node_key);

    void Delete_Node(Graph_Node* node);

    Graph_Edge* Insert_Edge(Graph_Node* from, Graph_Node* to);

    void Delete_Edge(Graph_Edge* edge);

    Rooted_Tree *BFS(Graph_Node *source) const;

    Rooted_Tree* SCC() const;
};


#endif //DSA_PROJECT_2_DYNAMIC_GRAPH_H
