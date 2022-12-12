// CS 3352, fall 2022
// Homework 7

#include "graph.h"

Graph::Graph(int numVertices)
{
   this->numVertices = numVertices;
   // Create the adjacency matrix.  A weight of 0 means no edge is present.
   edgeWeight = vector<vector<int> >(numVertices, vector<int>(numVertices, 0));
   // Initialize vector elements to indicate that BFS and DFS haven't been run yet.
   // A negative distance means infinity--BFS hasn't hit this vertex yet.
   distance = vector<int>(numVertices, -1);
   // Times of 0 mean DFS hasn't processed this vertex yet.
   discoveryTime = vector<int>(numVertices, 0);
   finishingTime = vector<int>(numVertices, 0);
   // A negative number means no vertex--DFS hasn't run yet.
   topologicalOrdering = vector<int>(numVertices, -1);
}

// Adds an unweighted edge to the graph.
void Graph::addEdge(int from, int to)
{
   // If no weight is indicated, weight 1 is assumed.
   addEdge(from, to, 1);
}

// Adds a weighted edge to the graph.
void Graph::addEdge(int from, int to, int weight)
{
   if (from >= 0 && from < numVertices && to >= 0 && to < numVertices && weight > 0)
   {
      // Only positive weights are allowed.
      edgeWeight.at(from).at(to) = weight;
   }
}

// Checks that the vectors filled in by BFS and DFS have the correct length.
bool Graph::areVectorLengthsCorrect() const
{
   return (
      static_cast<int>(distance.size()) == numVertices
      && static_cast<int>(discoveryTime.size()) == numVertices
      && static_cast<int>(finishingTime.size()) == numVertices
      && static_cast<int>(topologicalOrdering.size()) == numVertices
   );
}

// Returns a vertex's DFS discovery time.
int Graph::getDiscoveryTime(int v) const
{
   return discoveryTime.at(v);
}

// Returns a vertex's distance from the last source vertex used in BFS.
int Graph::getDistance(int v) const
{
   return distance.at(v);
}

// Returns an edge's weight.
int Graph::getEdgeWeight(int from, int to) const
{
   // Return a very large weight if no edge is present.
   return hasEdge(from, to) ? edgeWeight.at(from).at(to) : INT_MAX;
}

// Returns a vertex's DFS finishing time.
int Graph::getFinishingTime(int v) const
{
   return finishingTime.at(v);
}

// Returns the number of vertices in the graph.
int Graph::getNumVertices() const
{
   return numVertices;
}

// Returns the nth vertex in the topological ordering.
int Graph::getTopologicalOrdering(int n) const
{
   return topologicalOrdering.at(n);
}

// Returns true iff the given edge exists.
bool Graph::hasEdge(int from, int to) const
{
   // Only positive weights are allowed.
   return from >= 0 && from < numVertices && to >= 0 && to < numVertices && edgeWeight.at(from).at(to) > 0;
}

// Returns true iff the given vertex is currently colored black (already finished).
bool Graph::isVertexBlack(int v) const
{
   return getDiscoveryTime(v) > 0 && getFinishingTime(v) > 0;
}

// Returns true iff the given vertex is currently colored gray (already discovered but not yet finished).
bool Graph::isVertexGray(int v) const
{
   return getDiscoveryTime(v) > 0 && getFinishingTime(v) <= 0;
}

// Returns true iff the given vertex is currently colored white (not yet discovered).
bool Graph::isVertexWhite(int v) const
{
   return getDiscoveryTime(v) <= 0 && getFinishingTime(v) <= 0;
}

// Removes an edge from the graph.
void Graph::removeEdge(int from, int to)
{
   if (from >= 0 && from < numVertices && to >= 0 && to < numVertices)
   {
      // A weight of 0 means no edge is present.
      edgeWeight.at(from).at(to) = 0;
   }
}

// Resets the graph's distances, discovery times, finishing times and topological ordering.
void Graph::resetGraphResults()
{
   // Initialize vector elements to distinctive values that keep BFS and DFS from relying on them.
   distance = vector<int>(numVertices, 123456789);
   discoveryTime = vector<int>(numVertices, 123456789);
   finishingTime = vector<int>(numVertices, 123456789);
   topologicalOrdering = vector<int>(numVertices, 123456789);
}

// Resets the given vertex's discovery and finishing times.
void Graph::resetVertexToWhite(int v)
{
   discoveryTime.at(v) = 0;
   finishingTime.at(v) = 0;
}

// Returns true iff the given vertex has received a finite distance during a breadth-first search.
bool Graph::wasReachedByBFS(int v) const
{
   // Negative numbers are considered infinite.
   return distance.at(v) >= 0;
}

// Read the input as commands that apply to a graph and report results.
int main()
{
   Graph g;
   int n, u, v;
   string command;
   while (cin >> command)
   {
      if (command == "newgraph")
      {
         cin >> n;
         g = Graph(n);
         while (cin >> u && u > 0 && u <= n && cin >> v && v > 0 && v <= n)
         {
            g.addEdge(u - 1, v - 1);
         }
      }
      else if (command == "bfs" && g.getNumVertices() > 0)
      {
         cin >> u;
         g.resetGraphResults();
         g.breadthFirstSearch(u - 1);
         if (!g.areVectorLengthsCorrect())
         {
            cout << "BFS: INCORRECT VECTOR LENGTH(S)\n";
         }
         cout << "bfsdistances";
         for (v = 0; v < g.getNumVertices(); v += 1)
         {
            if (g.wasReachedByBFS(v))
            {
               cout << " " << g.getDistance(v);
            }
            else
            {
               cout << " X";
            }
         }
         cout << "\n";
      }
      else if (command == "dfs" && g.getNumVertices() > 0)
      {
         g.resetGraphResults();
         g.depthFirstSearch();
         if (!g.areVectorLengthsCorrect())
         {
            cout << "DFS: INCORRECT VECTOR LENGTH(S)\n";
         }
         cout << "dfstimes";
         for (v = 0; v < g.getNumVertices(); v += 1)
         {
            cout << " " << g.getDiscoveryTime(v) << "/" << g.getFinishingTime(v);
         }
         cout << "\n"
              << "toposort";
         for (n = 0; n < g.getNumVertices(); n += 1)
         {
            cout << " " << g.getTopologicalOrdering(n) + 1;
         }
         cout << "\n";
      }
      else
      {
         cout << "bad command\n";
      }
   }
   return 0;
}
