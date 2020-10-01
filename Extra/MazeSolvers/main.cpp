#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

#include "Maze.h"


//Solve a copy of the given maze with iterative breadth first search
void solveBFS(Maze theMaze, const Location& start, const Location& goal);

//Solve a copy of the given maze with iterative depth first search
void solveDFS(Maze theMaze, const Location& start, const Location& goal);

//Solve a copy of the given maze with recursive search
void findPathRecursive(Maze& curMaze, const Location& current, const Location& goal, bool& done);


int main()
{
    Maze theMaze;
    theMaze.print();

    Location start;
    Location goal;

    cout << "Enter start row & col with space between:" << endl;
    cin >> start.row >> start.col;

    cout << "Enter destination row & col with space between:" << endl;
    cin >> goal.row >> goal.col ;

    cout << "Solved with BFS:" << endl;
    solveBFS(theMaze, start, goal);

    cout << "Solved with DFS:" << endl;
    solveDFS(theMaze, start, goal);

    cout << "Solved with recurzion:" << endl;
    Maze mazeCopy = theMaze;
    bool isDone = false;
    findPathRecursive(mazeCopy, start, goal, isDone);
}



//Solve a copy of the given maze with iterative breadth first search
void solveBFS(Maze theMaze, const Location& start, const Location& goal) {
    //Keep track of parent locations using a table
    unordered_map<Location, Location, LocationHasher> parentTable;

    //Queue of locations that need to be explored - store as list so we can print
    list<Location> explorationQueue;

    Location current = start;
    explorationQueue.push_back(start);
    while(current != goal && !explorationQueue.empty()) {
        //Move to next Location in queue
        current = explorationQueue.front();
        explorationQueue.pop_front();

        //Make a vector with the four neighbor locations
        vector<Location> neighbors(4, current);
        neighbors[0].col -= 1;
        neighbors[1].col += 1;
        neighbors[2].row -= 1;
        neighbors[3].row += 1;

        //Check each neighbor to see if it is valid and unknown
        for(auto neighbor : neighbors) {
            if(theMaze.locationValid(neighbor) && parentTable.find(neighbor) == parentTable.end()) {
                parentTable[neighbor] = current;
                explorationQueue.push_back(neighbor);
            }
        }
    }

    //Trace back to start through parentTable
    while(current != start) {
        theMaze.mark(current);
        current = parentTable[current];
    }
    theMaze.mark(current);

    theMaze.print();
}



//Solve a copy of the given maze with iterative depth first search
void solveDFS(Maze theMaze, const Location& start, const Location& goal) {
    //Keep track of parent locations using a table
    unordered_map<Location, Location, LocationHasher> parentTable;
    //Make table to keep track of which locations are finalized
    unordered_map<Location, bool, LocationHasher> exploredTable;

    //Stack of locations that need to be explored - store as list so we can print
    list<Location> explorationStack;

    Location current = start;
    explorationStack.push_back(start);
    while(current != goal && !explorationStack.empty()) {
        //Move to next Location in stack
        current = explorationStack.back();
        explorationStack.pop_back();

        //If already explored, skip this location
        if(exploredTable.find(current) != exploredTable.end())
            continue;

        exploredTable[current] = true;

        //Make a vector with the four neighbor locations
        vector<Location> neighbors(4, current);
        neighbors[0].col -= 1;
        neighbors[1].col += 1;
        neighbors[2].row -= 1;
        neighbors[3].row += 1;

        //Check each neighbor to see if it is valid and unexplored
        for(auto neighbor : neighbors) {
            if(theMaze.locationValid(neighbor) && exploredTable.find(neighbor) == exploredTable.end()) {
                //Update parent record but don't lock it down yet
                parentTable[neighbor] = current;
                explorationStack.push_back(neighbor);
            }
        }
    }

    //Trace back to start through parentTable
    while(current != start) {
        theMaze.mark(current);
        current = parentTable[current];
    }
    theMaze.mark(current);

    theMaze.print();
}



//Solve a copy of the given maze with recursive search
void findPathRecursive(Maze& curMaze, const Location& current, const Location& goal, bool& done) {
    //Check to see if location is unmarked and valid
    if(!curMaze.locationValid(current) || done) {
        return;
    }

    //mark our copy with the move
    curMaze.mark(current);

    if(current == goal) {
        done = true;
        curMaze.print();
    }

    vector<Location> neighbors(4, current);
    neighbors[3].col -= 1;
    neighbors[2].col += 1;
    neighbors[1].row -= 1;
    neighbors[0].row += 1;

    //Check each neighbor to see if it is valid and unexplored
    for(auto neighbor : neighbors) {
        findPathRecursive(curMaze, neighbor, goal, done);
    }

    //Gues this did not work, unmark this location
    curMaze.clear(current);
}
