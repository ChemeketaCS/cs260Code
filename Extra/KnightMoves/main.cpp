#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>

#include "Location.h"
using namespace std;

//Gets all valid moves a knight can make from given location
vector<Location> getPossibleMoves(const Location& from);

void printPath(const Location& from,
               const Location& to,
               const unordered_map<Location, Location, LocationHasher>& parentTable)
{
    list<Location> path;
    //Work backwards from goal to start to build up path
    Location curLoc = to;
    while(curLoc != from) {
        path.push_front(curLoc);
        curLoc = parentTable.at(curLoc);
    }
    path.push_front(from);

    //Print it out
    for(auto loc : path)
        cout << loc << " ";
    cout << endl;
}


int main()
{
    Location startLoc(2, 3);            //starting location
    Location goalLoc(8, 8);             //goal location

    //Map that will be used to store parent of each given node
    //  Maps a location to its parent location using LocationHasher as hash function
    unordered_map<Location, Location, LocationHasher> parentTable;
    parentTable[startLoc] = Location(-1, -1);   //mark start with dummy parent

    //Initialize search storage - queue of locations
    // We know we can reach these but have not explored them yet
    // Use a list instead of a std::queue so we can print it
    list<Location> queue;
    queue.push_back(startLoc);

    bool foundGoal = false;
    while( !queue.empty() && !foundGoal ) {
//        cout << endl << "Current queue: ";
//        for(auto l : queue)
//            cout << l << " ";
//        cout << endl;

        //Get the next state to explore from the queue
        Location curLocation = queue.front();
        queue.pop_front();

//        cout << "Exploring: " << curLocation << "  on path ";
//        printPath(startLoc, curLocation, parentTable);

        //Get all the moves from there
        vector<Location> moves = getPossibleMoves(curLocation);

        for(Location& move : moves) {
            //If we have never seen the destination
            if(parentTable.find(move) == parentTable.end()) {

                //Set its parent
                parentTable[move] = curLocation;

                //Stop search if we found goal
                if(move == goalLoc) {
                    foundGoal = true;
                    break;
                }

                //Add the new location to the queue of things to explore
                queue.push_back(move);
            }
        }
    }

    //Now print out path to goal if it was found (always should be)
    if(foundGoal) {
        cout << "Found path:" << endl;
        printPath(startLoc, goalLoc, parentTable);
    } else {
        cout << "Goal not found!" << endl;
    }
}


vector<Location> getPossibleMoves(const Location& from) {
    vector<Location> possibleMoves;

    //Ugly for loops generate each possible move for a knight
    //Can move up to -2 to +2 rows
    for(int rowMod = -2; rowMod <= 2; rowMod++) {
        if(rowMod == 0)
            continue;  //can't move 0 rows

        //Assume we move only 1 column. If we are moving just 1 row, move 2 cols
        int colsToMove = 1;
        if( rowMod == 1 || rowMod == -1 )
            colsToMove = 2;

        //Generate +/-1 col if moving 2 rows, +/-2 col if moving 1 row
        for(int colMod = -colsToMove; colMod <= colsToMove; colMod += 2 * colsToMove) {
            int newRow = from.row + rowMod;
            int newCol = from.col + colMod;

            //Only keep in bounds moves
            if( newRow >= 1 && newRow <= 8 &&
                newCol >= 1 && newCol <= 8)
            {
                possibleMoves.push_back(Location(newRow, newCol));
            }
        }
    }

    return possibleMoves;
}

