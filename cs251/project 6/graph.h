// graph.h <Starter Code>
// < Your name >
//
// Basic graph class using adjacency matrix representation.  Currently
// limited to a graph with at most 100 vertices.
//
//
// Adam T Koehler, PhD
// University of Illinois Chicago
// CS 251, Spring 2023
//
// Project Original Variartion By:
// Joe Hummel, PhD
// University of Illinois at Chicago
//
#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>
#include <map>

using namespace std;

template<typename VertexT, typename WeightT>
class graph {
 private:
  struct EdgeData {
    bool EdgeExists;
    WeightT Weight;

    EdgeData() {
      EdgeExists = false;
    }
  };

  map<VertexT, set<pair<VertexT, WeightT>>> AdjList; // adjacency list
  set<VertexT> Vertices; // set of all vertices

 public:
  //
  // constructor:
  //
  // Constructs an empty graph where n is the max # of vertices
  // you expect the graph to contain.
  //
  graph(int n) {}

  //
  // NumVertices
  //
  // Returns the # of vertices currently in the graph.
  //
  int NumVertices() const {
    return static_cast<int>(this->Vertices.size());
  }

  //
  // NumEdges
  //
  // Returns the # of edges currently in the graph.
  //
  int NumEdges() const {
    int count = 0;

    //
    // loop through the adjacency list and count how many
    // edges currently exist:
    //
    for (const auto& vertex : this->Vertices) {
      count += static_cast<int>(this->AdjList[vertex].size());
    }
    return count;
  }

  //
  // addVertex
  //
  // Adds the vertex v to the graph if there's room, and if so
  // returns true.  If the vertex already exists in the graph, then
  // false is returned.
  //
  bool addVertex(VertexT v) {
    if (this->Vertices.count(v) > 0) {  // vertex already exists:
      return false;
    }

    //
    // if we get here, vertex does not exist so insert into the
    // set of vertices:
    //
    this->Vertices.insert(v);
    return true;
  }

  //
  // addEdge
  //
  // Adds the edge (from, to, weight) to the graph, and returns
  // true.  If the vertices do not exist, false is returned.
  //
  // NOTE: if the edge already exists, the existing edge weight
  // is overwritten with the new edge weight.
  //
  bool addEdge(VertexT from, VertexT to, WeightT weight) {
    //
    // check that both vertices exist:
    //
    if (this->Vertices.count(from) == 0 || this->Vertices.count(to) == 0) {
      return false;
    }

    //
    // add the edge to the adjacency list, overwriting any existing
    // edge weight:
    //
    this->AdjList[from].insert(make_pair(to, weight));

    return true;
  }



  //
  // getWeight
  //
  // Returns the weight associated with a given edge.  If
  // the edge exists, the weight is returned via the reference
  // parameter and true is returned.  If the edge does not
  // exist, the weight parameter is unchanged and false is
  // returned.
  //
bool getWeight(VertexT from, VertexT to, WeightT& weight) const {
  auto fromIter = AdjList.find(from);
  if (fromIter == AdjList.end()) {
    return false;  // "from" vertex not found
  }

  auto toIter = fromIter->second.find({to, WeightT{}});
  if (toIter == fromIter->second.end()) {
    return false;  // edge not found
  }

  weight = toIter->second;
  return true;
}


  //
  // neighbors
  //
  // Returns a set containing the neighbors of v, i.e. all
  // vertices that can be reached from v along one edge.
  // Since a set is returned, the neighbors are returned in
  // sorted order; use foreach to iterate through the set.
  //
set<VertexT> neighbors(VertexT v) const {
  set<VertexT> S;

  auto itr = Vertices.find(v);
  if (itr == Vertices.end()) { // not found
    return S;
  }

  int row = itr->second; // found

  // loop over the adjacency list for the vertex and add vertices to S if the edge has v as its source vertex
  for (const auto& edge : AdjList[row]) {
    S.insert(edge.To);
  }

  return S;
}





  //
  // getVertices
  //
  // Returns a vector containing all the vertices currently in
  // the graph.
  //
  vector<VertexT> getVertices() const {
    return this->Vertices;  // returns a copy:
  }

  //
  // dump
  //
  // Dumps the internal state of the graph for debugging purposes.
  //
  // Example:
  //    graph<string,int>  G(26);
  //    ...
  //    G.dump(cout);  // dump to console
  //
void dump(ostream& output) const {
    output << "***************************************************" << endl;
    output << "********************* GRAPH ***********************" << endl;

    output << "**Num vertices: " << this->NumVertices() << endl;
    output << "**Num edges: " << this->NumEdges() << endl;

    output << endl;
    output << "**Vertices:" << endl;
    for (const auto& v : this->Vertices) {
        output << " " << v << endl;
    }

    output << endl;
    output << "**Edges:" << endl;
    for (const auto& kv : this->AdjList) {
        const auto& v = kv.first;
        const auto& adj = kv.second;
        output << " " << v << ": ";
        for (const auto& kv2 : adj) {
            const auto& u = kv2.first;
            const auto& weight = kv2.second;
            output << "(" << u << ", " << weight << ") ";
        }
        output << endl;
    }
    output << "**************************************************" << endl;
}



};
