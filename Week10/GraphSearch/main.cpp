#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"
#include "SearchTree.h"

using namespace std;


///Sets up a graph corresponding to that shown in BFS Worksheet
Graph<string> setupGraph() {

    string nodeNames[] = { "Node 0",
                           "Node 1",
                           "Node 2",
                           "Node 3",
                           "Node 4",
                           "Node 5",
                           "Node 6",
                           "Node 7" };

    Graph<string> graph(nodeNames, 8);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 0);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 5);
    graph.addEdge(1, 6);
    graph.addEdge(2, 4);
    graph.addEdge(4, 6);
    graph.addEdge(5, 6);
    graph.addEdge(6, 2);
    graph.addEdge(6, 4);
    graph.addEdge(6, 5);
    graph.addEdge(6, 7);
    graph.addEdge(7, 6);

    return graph;
}


int main()
{
    Graph<string> ourGraph = setupGraph();

    ourGraph.printAdjacencyList();
    cout << "--------------------------------------" << endl;
    ourGraph.printAdjacencyMatrix();
    cout << "--------------------------------------" << endl;
    cout << "--------------------------------------" << endl;



    ///-----------------------Do searches---------------------

    cout << endl << "Breadth first searches:" << endl;
    SearchTree bfsResult1 = ourGraph.bfs(5);
    bfsResult1.printAllPaths();
    cout << "--------------------------------------" << endl;
    SearchTree bfsResult2 = ourGraph.bfs(1);
    bfsResult2.printAllPaths();
    cout << "--------------------------------------" << endl;
    cout << "--------------------------------------" << endl;

    cout << endl << "Depth first searches:" << endl;
    SearchTree dfsResult1 = ourGraph.dfsIterative(5);
    dfsResult1.printAllPaths();
    cout << "--------------------------------------" << endl;
    SearchTree dfsResult2 = ourGraph.dfsIterative(1);
    dfsResult2.printAllPaths();
    cout << "--------------------------------------" << endl;


    cout << endl << "Depth first searches:" << endl;
    SearchTree dfsResult1b = ourGraph.dfsRecursive(5);
    dfsResult1b.printAllPaths();
    cout << "--------------------------------------" << endl;
    SearchTree dfsResult2b = ourGraph.dfsRecursive(1);
    dfsResult2b.printAllPaths();
    cout << "--------------------------------------" << endl;

    return 0;
}
