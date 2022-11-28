#ifndef GRAPH_H
#define GRAPH_H

#include "SearchTree.h"
#include <vector>
#include <list>
#include <queue>

using namespace std;

/** Represents a possibly directed graph where nodes are of type T
    Internal storage based on an AdjacencyList
**/
template <typename T>
class Graph
{
private:
    // List of values vertices represent
    vector<T> vertexValues;

    // List of edge lists of each vertex
    // could replace inner vertex with list to reduce storage overhead
    vector< vector<int> > neighbors;

public:
    /** Construct an empty graph */
    Graph();

    /** Construct a graph from an array of vertex names */
    Graph(T vertexValues[], int size);

    /** Return the number of vertices in the graph */
    int getSize() const;

    /** Return the degree for a specified vertex */
    int getDegree(int v) const;

    /** Return the vertex for the specified index */
    T getVertex(int index) const;

    /** Return the index for the specified vertex */
    int getIndex(T v) const;

    /** Return the vertices in the graph */
    vector<T> getVertices() const;

    /** Return the neighbors of vertex v */
    vector<int> getNeighbors(int v) const;

    /** Add a directed edge connecting vertex v to vertex u **/
    void addEdge(int v, int u);

    void printAdjacencyList() const;
    void printAdjacencyMatrix() const;

    /** bfs search from vertex v
        Return a SearchTree representing what is discovered
    */
    SearchTree bfs(int v) const;

    /** dfs search from vertex v
        Return a SearchTree representing what is discovered
    */
    SearchTree dfsRecursive(int v) const;
    SearchTree dfsIterative(int v) const;

private:
    void dfsRecursiveHelper(int curLocation, vector<int>& parent, vector<bool>& visited) const;
};

template <typename T>
Graph<T>::Graph()
{
}

template <typename T>
Graph<T>::Graph(T vertices[], int size)
{
    //store the values associated with each vertex
    for(int i = 0; i < size; i++)
        vertexValues.push_back(vertices[i]);

    //make an empty list of edges for each vertex
    for(int i = 0; i < size; i++)
        neighbors.push_back(vector<int>());
}

template <typename T>
int Graph<T>::getSize() const
{
    return vertexValues.size();
}

template <typename T>
int Graph<T>::getDegree(int v) const
{
    return neighbors[v].size();
}

template <typename T>
T Graph<T>::getVertex(int index) const
{
    return vertexValues[index];
}

template <typename T>
int Graph<T>::getIndex(T v) const
{
    for (int i = 0; i < vertexValues.size(); i++)
    {
        if (vertexValues[i] == v)
            return i;
    }

    return -1; // If vertex is not in the graph
}

template <typename T>
vector<T> Graph<T>::getVertices() const
{
    return vertexValues;
}

template <typename T>
vector<int> Graph<T>::getNeighbors(int v) const
{
    return neighbors[v];
}

template <typename T>
void Graph<T>::addEdge(int u, int v)
{
    neighbors[u].push_back(v);
}

template <typename T>
void Graph<T>::printAdjacencyList() const
{
    cout << "Adjaceny list format:" << endl;
    for (size_t u = 0; u < neighbors.size(); u++)
    {
        cout << "Vertex " << u << ": ";
        for (size_t v = 0; v < neighbors[u].size(); v++)
        {
            cout << neighbors[u][v] << " ";
        }
        cout << endl;
    }
}

template <typename T>
void Graph<T>::printAdjacencyMatrix() const
{
    cout << "Adjaceny matrix format:" << endl;

    size_t size = vertexValues.size();
    // Use vector for 2-D array
    vector< vector<int> > adjacencyMatrix(size);

    // Initialize 2-D array for adjacency matrix
    for (size_t i = 0; i < size; i++)
    {
        adjacencyMatrix[i] = vector<int>(size);
    }

    for (size_t u = 0; u < neighbors.size(); u++)
    {
        //for each neighbor
        for (size_t j = 0; j < neighbors[u].size(); j++)
        {
            //figure out its index
            int v = neighbors[u][j];

            //update matrix at that index
            adjacencyMatrix[u][v] = 1;
        }
    }

    for (size_t i = 0; i < adjacencyMatrix.size(); i++)
    {
        for (size_t j = 0; j < adjacencyMatrix[i].size(); j++)
        {
            cout << adjacencyMatrix[i][j] << " ";
        }

        cout << endl;
    }
}


template <typename T>
SearchTree Graph<T>::bfs(int startVertex) const
{
    //list of parent node in search tree for each vertex - all initalized to no parent (-1)
    vector<int> parentList(vertexValues.size(), -1);

    //list of vertices that we have seen - all start as false except for starting vertex
    vector<bool> isSeen(vertexValues.size(), false);
    isSeen[startVertex] = true;

    //queue of vertices we need to explore - initially just the starting point
    list<int> queue;
    queue.push_back(startVertex);

    while (!queue.empty())
    {
        int u = queue.front(); // Get the next vertex in queue
        queue.pop_front(); // Remove it from queue

        //for each edge from parent
        for (size_t j = 0; j < neighbors[u].size(); j++)
        {
            int neighbor = neighbors[u][j];
            if (!isSeen[neighbor])
            {
                queue.push_back(neighbor); // Add it to exploration queue
                parentList[neighbor] = u;  // The parent of w is u
                isSeen[neighbor] = true;
            }
        }
    }

    return SearchTree(startVertex, parentList);
}

template <typename T>
SearchTree Graph<T>::dfsIterative(int startVertex) const
{
    //list of parent node in search tree for each vertex - all initalized to no parent (-1)
    vector<int> parentList(vertexValues.size(), -1);

    //list of vertices that we have visited - initially nothing
    vector<bool> isVisited(vertexValues.size(), false);

    //stack of vertices we need to explore - initially just the starting point
    list<int> stack;
    stack.push_back(startVertex);

    while (!stack.empty())
    {
        int u = stack.back();   // Get the top vertex in stack
        stack.pop_back();       // Remove it from stack

        if(!isVisited[u]) {
            isVisited[u] = true;

            //for each edge from parent
            // do in reverse order so edge to lowest index vertex gets explored first
            for (int j = static_cast<int>(neighbors[u].size()) - 1; j >= 0; j--)
            {
                int neighbor = neighbors[u][j];
                if (!isVisited[neighbor])
                {
                    stack.push_back(neighbor); // Add it to exploration stack
                    parentList[neighbor] = u;  // The parent of w is u
                }
            }
        }
    }

    return SearchTree(startVertex, parentList);
}

template <typename T>
SearchTree Graph<T>::dfsRecursive(int startVertex) const {
    //list of parent node in search tree for each vertex - all initalized to no parent (-1)
    vector<int> parentList(vertexValues.size(), -1);

    //list of vertices that we have visited - initially nothing
    vector<bool> isVisited(vertexValues.size(), false);

    dfsRecursiveHelper(startVertex, parentList, isVisited);

    return SearchTree(startVertex, parentList);
}


template <typename T>
void Graph<T>::dfsRecursiveHelper(int curLocation, vector<int>& parentList, vector<bool>& isVisited) const
{
    isVisited[curLocation] = true;
    for(int i : neighbors[curLocation]) {
        if(isVisited[i] == false) {
            parentList[i] = curLocation;
            dfsRecursiveHelper(i, parentList, isVisited);
        }
    }
}



#endif
