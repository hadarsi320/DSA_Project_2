#include <iostream>
#include "Queue.h"
#include "Dynamic_Graph.h"

int main()
{
    Dynamic_Graph *dynamicGraph = new Dynamic_Graph();
    Graph_Node *node0 = dynamicGraph->Insert_Node(0);
    Graph_Node *node1 = dynamicGraph->Insert_Node(1);
    Graph_Edge *edge0 = dynamicGraph->Insert_Edge(node0, node1);

    dynamicGraph->Delete_Node(node0);
    dynamicGraph->Delete_Edge(edge0);
    dynamicGraph->Delete_Node(node1);
    delete dynamicGraph;
    int x = 1;
}