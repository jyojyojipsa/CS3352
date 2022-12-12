// CS 3352, fall 2022
// Homework 7

#ifndef GRAPH_H
#define GRAPH_H

#include <climits>
#include <iostream>
#include <queue>

using namespace std;

// Class definition.

class Graph
{
private:
   vector<vector<int> > edgeWeight;
   int numVertices;
   vector<int> distance;
   vector<int> discoveryTime;
   vector<int> finishingTime;
   int time;
   vector<int> topologicalOrdering;
   void depthFirstSearchVisit(int u);
public:
   Graph(int numVertices = 0);
   void addEdge(int from, int to);
   void addEdge(int from, int to, int weight);
   bool areVectorLengthsCorrect() const;
   void breadthFirstSearch(int sourceVertex);
   void depthFirstSearch();
   int getDiscoveryTime(int v) const;
   int getDistance(int v) const;
   int getEdgeWeight(int from, int to) const;
   int getFinishingTime(int v) const;
   int getNumVertices() const;
   int getTopologicalOrdering(int v) const;
   bool hasEdge(int from, int to) const;
   bool isVertexBlack(int v) const;
   bool isVertexGray(int v) const;
   bool isVertexWhite(int v) const;
   void removeEdge(int from, int to);
   void resetGraphResults();
   void resetVertexToWhite(int v);
   bool wasReachedByBFS(int v) const;
};

#endif // #ifndef GRAPH_H
