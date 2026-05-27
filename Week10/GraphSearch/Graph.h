#ifndef GRAPH_H
#define GRAPH_H

#include <format>
#include <iostream>
#include <list>
#include <stdexcept>
#include <unordered_map>
#include <vector>

template<typename T>
class Graph {
public:
  void addVertex(T vertex);
  void removeVertex(T vertex);
  bool hasVertex(T vertex) const;
  void addEdge(T source, T destination, int weight = 1, bool directed = true);
  void removeEdge(T source, T destination);
  bool hasEdge(T source, T destination) const;
  int getEdgeWeight(T source, T destination) const;
  std::list<T> getNeighbors(T vertex) const;
  void printAdjacencyList() const;
  void printAdjacencyMatrix() const;

private:
  std::unordered_map<T, std::unordered_map<T, int>> adjacencyMap;
};

template<typename T>
void Graph<T>::addVertex(T vertex) {
  if (!adjacencyMap.contains(vertex)) {
    adjacencyMap.insert({vertex, std::unordered_map<T, int>()});
  }
}

template<typename T>
void Graph<T>::removeVertex(T vertex) {
  // erase returns count of how many records were erased
  size_t count = adjacencyMap.erase(vertex);
  // if vertex removed, also check all other vertices and remove any edges to
  // this vertex
  if (count > 0) {
    for (auto& [v, neighbors] : adjacencyMap) {
      neighbors.erase(vertex);
    }
  }
}

template<typename T>
bool Graph<T>::hasVertex(T vertex) const {
  return adjacencyMap.contains(vertex);
}

template<typename T>
void Graph<T>::addEdge(T source, T destination, int weight, bool directed) {
  // for convenience, if source or destination do not exist, add them
  addVertex(source);
  addVertex(destination);

  // add or update the edge from source to destination with the given weight
  adjacencyMap.at(source).insert({destination, weight});

  if (!directed) {
    // add or update the edge from destination to source with the given weight
    adjacencyMap.at(destination).insert({source, weight});
  }
}

template<typename T>
void Graph<T>::removeEdge(T source, T destination) {
  if (adjacencyMap.contains(source)) {
    adjacencyMap.at(source).erase(destination);
  }
}

template<typename T>
bool Graph<T>::hasEdge(T source, T destination) const {
  if (adjacencyMap.contains(source)) {
    return adjacencyMap.at(source).contains(destination);
  }
  return false;
}

template<typename T>
int Graph<T>::getEdgeWeight(T source, T destination) const {
  if (adjacencyMap.contains(source)
      && adjacencyMap.at(source).contains(destination)) {
    return adjacencyMap.at(source).at(destination);
  }
  throw std::logic_error("Edge does not exist");
}

template<typename T>
std::list<T> Graph<T>::getNeighbors(T vertex) const {
  // Return a list of the neighbors of the given vertex.
  // If the vertex does not exist, return an empty list.
  std::list<T> neighborsList;
  if (adjacencyMap.contains(vertex)) {
    for (const auto& [neighbor, weight] : adjacencyMap.at(vertex)) {
      neighborsList.push_back(neighbor);
    }
  }
  return neighborsList;
}

template<typename T>
void Graph<T>::printAdjacencyList() const {
  for (const auto& [vertex, neighbors] : adjacencyMap) {
    std::cout << vertex << ": ";
    for (const auto& [neighbor, weight] : neighbors) {
      std::cout << neighbor << "(" << weight << ") ";
    }
    std::cout << std::endl;
  }
}

template<typename T>
void Graph<T>::printAdjacencyMatrix() const {
  // Get a list of all vertices to maintain a consistent order
  std::vector<T> vertices;
  for (const auto& [vertex, _] : adjacencyMap) {
    vertices.push_back(vertex);
  }

  // Print header
  std::cout << "    ";
  for (const auto& vertex : vertices) {
    std::cout << std::format("{:4}", vertex);
  }
  std::cout << std::endl;

  // Print each row of the adjacency matrix
  for (const auto& vertex : vertices) {
    std::cout << std::format("{}", vertex);
    for (const auto& otherVertex : vertices) {
      if (adjacencyMap.contains(vertex)
          && adjacencyMap.at(vertex).contains(otherVertex)) {
        std::cout << std::format("{:4}",
                                 adjacencyMap.at(vertex).at(otherVertex));
      } else {
        std::cout << "   0";
      }
    }
    std::cout << std::endl;
  }
}

#endif
