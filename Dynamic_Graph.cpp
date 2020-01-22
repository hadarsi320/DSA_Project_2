//
// Created by Hadar on 18-Jan-20.
//

#include "Dynamic_Graph.h"

Dynamic_Graph::Dynamic_Graph() : _firstGraphNode(NULL), _firstGraphEdge(NULL) {}

Dynamic_Graph::~Dynamic_Graph()
{
    Graph_Edge * edgePtr;
    while(_firstGraphEdge != NULL)
    {
        edgePtr = _firstGraphEdge->getNextEdge();
        delete _firstGraphEdge;
        _firstGraphEdge = edgePtr;
    }

    Graph_Node * nodePtr;
    while(_firstGraphNode != NULL)
    {
        nodePtr = _firstGraphNode->getNextNode();
        delete _firstGraphNode;
        _firstGraphNode = nodePtr;
    }
}

Graph_Node *Dynamic_Graph::Insert_Node(unsigned node_key)
{
    Graph_Node *newNode = new Graph_Node(node_key);
    if(_firstGraphNode == NULL)
        _firstGraphNode = newNode;
    else
    {
        newNode->setNextNode(_firstGraphNode);
        _firstGraphNode->setPrevNode(newNode);
        _firstGraphNode = newNode;
    }
    return _firstGraphNode;
}

void Dynamic_Graph::Delete_Node(Graph_Node *node)
{
    if(node->Get_in_Degree() == 0 and node->Get_out_Degree() == 0)
    {
        if(node == _firstGraphNode)
        {
            _firstGraphNode = node->getNextNode();
            if (_firstGraphNode != NULL)
                _firstGraphNode->setPrevNode(NULL);
        }

        if(node->getNextNode() != NULL)
            node->getNextNode()->setPrevNode(node->getPrevNode());

        if(node->getPrevNode() != NULL)
            node->getPrevNode()->setNextNode(node->getNextNode());

        delete node;
    }
}

Graph_Edge *Dynamic_Graph::Insert_Edge(Graph_Node *from, Graph_Node *to)
{
    Graph_Edge *newEdgePtr = new Graph_Edge(from, to);

    if(_firstGraphEdge == NULL)
        _firstGraphEdge = newEdgePtr;
    else
    {
        newEdgePtr->setNextEdge(_firstGraphEdge);
        _firstGraphEdge->setPrevEdge(newEdgePtr);
        _firstGraphEdge = newEdgePtr;
    }

    return _firstGraphEdge;
}

void Dynamic_Graph::Delete_Edge(Graph_Edge *edge)
{
    if(edge == _firstGraphEdge)
    {
        _firstGraphEdge = edge->getNextEdge();
        if(_firstGraphEdge != NULL)
            _firstGraphEdge->setPrevEdge(NULL);
    }

    if(edge->getNextEdge() != NULL)
        edge->getNextEdge()->setPrevEdge(edge->getPrevEdge());

    if(edge->getPrevEdge() != NULL)
        edge->getPrevEdge()->setNextEdge(edge->getNextEdge());

    delete edge;
}

void Dynamic_Graph::BFS_Initialization(Graph_Node *s, Queue<BfsPair> *queue,
                                       Rooted_Tree *bfsTree) const {
    resetColors();
    s->color = GREY;
    Tree_Node *root = new Tree_Node(s->getKey());
    bfsTree->setRoot(root);
    queue->enqueue(new BfsPair(s, root));
}

Rooted_Tree *Dynamic_Graph::BFS(Graph_Node *source) const
{
    // initialize BFS
    Queue<Pair<Graph_Node, Tree_Node>> queue;
    Rooted_Tree *bfsTree = new Rooted_Tree;
    BFS_Initialization(source, &queue, bfsTree);

    BfsPair *currentPair = NULL;
    ListItem<Graph_Node> *currentNeighbour = NULL;
    Tree_Node *currentLeftChild = NULL;
    Graph_Node *currentNode = NULL;
    while (!queue.isEmpty())
    {
        currentPair = queue.dequeue();
        currentNeighbour = currentPair->first->getFirstOutNeighbour();
        while (currentNeighbour != NULL)
        {
            currentNode = currentNeighbour->getData();
            if (currentNode->color == WHITE)
            {
                currentNode->color = GREY;
                Tree_Node *matchingTreeNode = new Tree_Node(currentNode->getKey());
                matchingTreeNode->setParent(currentPair->second);
                if (currentLeftChild == NULL)
                    currentPair->second->setLeftChild(matchingTreeNode);
                else
                    currentLeftChild->setRightSibling(matchingTreeNode);
                currentLeftChild = matchingTreeNode;
                queue.enqueue(new BfsPair(currentNode, matchingTreeNode));
            }
            currentNeighbour = currentNeighbour->getNext();
        }
        currentPair->first->color = BLACK;
        delete currentPair;
        currentLeftChild = NULL;
    }
    return bfsTree;
}

void Dynamic_Graph::resetColors() const {
    Graph_Node *ptr = _firstGraphNode;
    while (ptr != NULL)
    {
        ptr->color = WHITE;
        ptr = ptr->getNextNode();
    }
}

//Stack <Graph_Node> Dynamic_Graph::generatePsi() {
//    resetColors();
//
//}
