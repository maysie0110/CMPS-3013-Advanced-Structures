#include "Graph.h"

using namespace std;

Graph::Graph(int V)
{
	numVertices = V;
	AdjList.resize(V);
	visited.resize(V);
	//for (auto v : AdjList)
	//	myColor = WHITE;
}


Graph::~Graph()
{
}


void Graph::addEdge(int v, int w)
{
	AdjList[v].push_back(w);

}

//Depth-first search
void Graph::DFS()
{
	//initialy, all vertices are WHITE and has not been visited
	for (int i = 0; i < numVertices; i++)
		visited[i] = false;

	//for each vertex that is adjacent to current vertex
	for (int i = 0; i < numVertices; i++)
		if (visited[i] == false)
			DFS_Visit(i, visited); //call depth first search 
}


void Graph::DFS_Visit(int i, vector<bool> visited)
{
	//set color to GREY, this vertex has been visited
	visited[i] = true;

	for (auto v : AdjList[i])
		if (!visited[v])
			DFS_Visit(v, visited);
}

//Breadth-First search
void Graph::BFS(int s)
{
	//initially, all vertices are WHITE and has not been visited
	for (int i = 0; i < numVertices; i++)
		visited[i] = false;

	queue<int> Q; 
	visited[s] = true; //mark the current node as visted
	Q.push(s);

	while (!Q.empty()) {
		s = Q.front();
		Q.pop();

		for (auto v : AdjList[s]) {
			if (!visited[v]) {
				visited[v] = true;
				Q.push(v);
			}
		}
	}
}


int Graph::ShortestPath()
{
	// TODO: Add your implementation code here.
	return 0;
}
