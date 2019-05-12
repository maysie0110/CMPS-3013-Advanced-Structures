#include<iostream>
#include<vector>
#include"Graph.h"
//enum Color {WHITE, GREY, BLACK};
using namespace std;

int main() {
	char c;
	int m, n;
	cin >> m >> n; //number of rows and columns

	//build an adjacency list
	//vector <vector<int>> AdjList(m);
	//vector <int> AdjList(m);
	Graph myGraph(m);
	//read input to the graph


	while (m != 0) { //end of the input
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> c;
				myGraph.addEdge(i, c);
			}
		}
	}

	myGraph.DFS();
	return 0;
}
