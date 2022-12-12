// YOUR NAME: Kangmin Kim
// CS 3352, fall 2021
// Homework 7

#include "graph.h"



void Graph::breadthFirstSearch(int sourceVertex)
{
   int i = 0 , j = 0;
   
   
  
  // Use a queue<int> and its push, empty, front and pop member functions.
   queue<int> myQueue = {};
	
	
	
    for (i = 0; i < getNumVertices(); ++i)
      {
		   distance.at(i) = -1; 
		   // Each distance.at(v) should be set to vertex v's distance from
		}
		 distance.at(sourceVertex) = 0;
		 // sourceVertex; use -1 to mean infinity.  When you need to consider a
		 myQueue.push(sourceVertex);
       
	while (!myQueue.empty())
	{
		j = myQueue.front();
		myQueue.pop();
		for(i = 0; i < getNumVertices(); ++i) 
		{
		  if(hasEdge(j,i) && wasReachedByBFS(i) == 0)
		  { // getNumVertices, hasEdge and wasReachedByBFS member functions will be
	      distance.at(i) = distance.at(j) + 1; // set of vertices, consider them in ascending order.
	      myQueue.push(i);  	
		  }
		}
	  } 
		 
}

void Graph::depthFirstSearch()
{
   // Each discoveryTime.at(v) and finishingTime.at(v) should be set to
   // vertex v's discovery and finishing times.  The topologicalOrdering
   // vector should be filled with the vertex numbers in topological order
   // (for example, topologicalOrdering.at(0) should be the number of the
   // first vertex in the topological ordering).  Use the discovery and
   // finishing times of a vertex to determine its color.
    int i = 0 , j = 0, tmp1 = 0, tmp2 = 0;
	
	time = 0;

   for(i = 0; i < getNumVertices(); ++i)
       {
		   resetVertexToWhite(i);
	   }
   //	When you need to
   // consider a set of vertices, consider them in ascending order.  The
   // getNumVertices, resetVertexToWhite, isVertexWhite and hasEdge member
   // functions will be useful.
	for(i = 0; i < getNumVertices(); ++i)
	{
		if(isVertexWhite(i))
			depthFirstSearchVisit(i);
	}

	for(i = 0; i < getNumVertices(); ++i)
	{
		topologicalOrdering.at(i) = i;
	}

	for(i = 0; i < getNumVertices(); ++i)
	{		
		for(j = i + 1; j < getNumVertices(); ++j)
		{  
			tmp1 = topologicalOrdering.at(i);
			tmp2 = topologicalOrdering.at(j);
			
			if(finishingTime.at(tmp1) < finishingTime.at(tmp2))
			{
				topologicalOrdering.at(i) = tmp2;
				topologicalOrdering.at(j) = tmp1;
			}
		}
	}
}


void Graph::depthFirstSearchVisit(int u)
{
	++time;
	discoveryTime.at(u) = time;
	
	for(int v = 0; v < getNumVertices(); ++v)
	{ 
		if(hasEdge(u,v))
			if(isVertexWhite(v))
			   depthFirstSearchVisit(v);
	}
	++time;
	finishingTime.at(u) = time;
}


// CS 3352, fall 2022
// Homework 7
/*
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
*/