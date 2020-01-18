#include <iostream>
#include "Queue.h"
#include "Dynamic_Graph.h"
#include "Rooted_Tree.h"
#include <sstream> //TODO remove this kaki flotz
#include <string>
#include <iostream>

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

    //===================================================
    // Creating 13 new Tree_Nodes
    Tree_Node nodes[14];
    for (int i=0; i <= 13; i++) {
        nodes[i].setKey(i);
    }

    // Setting parents
    for (int i=1; i<=3; i++) {
        nodes[i].setParent(&nodes[0]);
    }
    for (int i=4; i<=5; i++) {
        nodes[i].setParent(&nodes[1]);
    }
    for (int i=6; i<=9; i++) {
        nodes[i].setParent(&nodes[2]);
    }
    nodes[10].setParent(&nodes[3]);
    nodes[11].setParent(&nodes[5]);
    for (int i=12; i<=13; i++) {
        nodes[i].setParent(&nodes[8]);
    }

    // Setting children
    nodes[0].setLeftChild(&nodes[1]);
    nodes[1].setLeftChild(&nodes[4]);
    nodes[2].setLeftChild(&nodes[6]);
    nodes[3].setLeftChild(&nodes[10]);
    nodes[5].setLeftChild(&nodes[11]);
    nodes[8].setLeftChild(&nodes[12]);

    // Setting siblings
    nodes[1].setRightSibling(&nodes[2]);
    nodes[2].setRightSibling(&nodes[3]);
    nodes[4].setRightSibling(&nodes[5]);
    nodes[6].setRightSibling(&nodes[7]);
    nodes[7].setRightSibling(&nodes[8]);
    nodes[8].setRightSibling(&nodes[9]);
    nodes[12].setRightSibling(&nodes[13]);

    // Create Rooted_Tree
    Rooted_Tree rootedTree;
    rootedTree.setRoot(&nodes[0]);

    // printing
    std::stringbuf buffer;      // empty stringbuf
    std::ostream os (&buffer);  // associate stream buffer to stream
    // mixing output to buffer with inserting to associated stream:
    buffer.sputn ("",0);
    rootedTree.Print_By_Layer(os);
    std::cout << buffer.str() << std::endl;
}