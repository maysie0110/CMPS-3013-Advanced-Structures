#pragma once
#include<vector>
#include<queue>

using namespace std;
class Graph
{
	int numVertices;//number of vertices
	vector <vector<char>> AdjList;
	vector <bool> visited;
	//vector<char> Color;
	//Color myColor;
public:
	Graph(int V);
	~Graph();

	void addEdge(int v, int w);
	void DFS();
	void DFS_Visit(int v, vector<bool> visted);
	void BFS(int s);
	int ShortestPath();
};

