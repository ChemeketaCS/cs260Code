#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
using namespace std;

class SearchTree
{
public:
    /** Construct a tree with root, parent, and searchOrder */
    SearchTree(unsigned startVertex, vector<int>& parents);

    /** Return the root of the tree */
    int getRoot();

    /** Return the parent of vertex v */
    int getParent(int v);

    /** Return the path of vertices from root to v in reverse order **/
    vector<int> getPath(int v);

    /** Print every search path */
    void printAllPaths();

private:
    unsigned int root;      // The root of the tree
    vector<int> parentList; // Store the parent of each vertex
};


SearchTree::SearchTree(unsigned int startVertex, vector<int>& parents) {
    this->root = startVertex;
    this->parentList = parents;
}

int SearchTree::getRoot() {
    return root;
}

int SearchTree::getParent(int v) {
    return parentList[v];
}

vector<int> SearchTree::getPath(int v) {
    vector<int> path;

    do
    {
        path.push_back(v);
        v = parentList[v];
    }
    while (v != -1);

    return path;
}

void SearchTree::printAllPaths() {
    cout << "Found paths given root " << root << endl;
    for (unsigned int i = 0; i < parentList.size(); i++) {
        cout << i << " : ";

        if (parentList[i] != -1) {
            // We can get there - get path, print in reverse order
            vector<int> path = getPath(i);
            for(int j = static_cast<int>(path.size()) - 1; j >= 0; j--) {
                cout << path[j] << " ";
            }

            cout << endl;
        } else {
            if(i == root) {
                cout << "root" << endl;
            } else {
                cout << "unreachable" << endl;
            }
        }
    }
}


#endif
