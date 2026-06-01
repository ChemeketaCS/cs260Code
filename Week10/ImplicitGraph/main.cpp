#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Position {
  int row;
  int col;

  Position(): row(0), col(0) {
  }
  Position(int r, int c): row(r), col(c) {
  }

  // Define equality operator for Position to allow comparison in unordered_map
  bool operator==(const Position& other) const {
    return row == other.row && col == other.col;
  }
};

// Specialize std::hash for Position to allow it to be used as a key in
// unordered_map
namespace std {
template<>
struct hash<Position> {
  size_t operator()(const Position& pos) const {
    return hash<int>()(pos.row) ^ (hash<int>()(pos.col) << 1);
  }
};
} // namespace std

// generate a list of possible knight moves from a given position
list<Position> getKnightMoves(const Position& pos) {
  list<Position> moves;
  list<pair<int, int>> directions = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                                     {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};


{
 {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
 {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
}
  // given pos and our list of directions, generate new positions
  //  and check if they are on the board
  for (const auto& [dr, dc] : directions) {
    int newRow = pos.row + dr;
    int newCol = pos.col + dc;
    if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
      moves.push_back(Position(newRow, newCol));
    }
  }
  return moves;
}

int main() {
  Position start(2, 3);
  Position destination(6, 6);

  // BFS
  // queue for BFS
  list<Position> queue;
  // parentMap will also serve as a visited set
  unordered_map<Position, Position> parentMap;
  queue.push_back(start);
  bool found = false;
  while (!queue.empty()) {
    Position current = queue.front();
    queue.pop_front();

    if (current == destination) {
      found = true;
      break;
    }

    for (const auto& neighbor : getKnightMoves(current)) {
      if (!parentMap.contains(neighbor)) {
        parentMap.insert({neighbor, current});
        queue.push_back(neighbor);
      }
    }
  }

  // If we found the destination, reconstruct the path using parentMap
  if (found) {
    Position current = destination;
    while (current != start) {
      cout << "(" << current.row << ", " << current.col << ") <- ";
      current = parentMap[current];
    }
    cout << "(" << start.row << ", " << start.col << ")" << endl;
    cout << endl;
  } else {
    cout << "No path found." << endl;
  }
}