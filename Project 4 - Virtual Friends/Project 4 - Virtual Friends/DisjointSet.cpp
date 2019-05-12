#include "DisjointSet.h"


//constructor performing make sets
DisjointSet::DisjointSet(int num)
{
	parent.assign(num, 0);
	rank.assign(num, 0);

	//Creates a single-set containing
	for (int i = 0; i < num; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
	setSize.assign(num, 1);
	
}

//destructor
DisjointSet::~DisjointSet()
{
	while (!parent.empty() && !rank.empty() && !setSize.empty()) {
		parent.pop_back();
		rank.pop_back();
		setSize.pop_back();
	}
}

//return the parent/root of the set that contains x
//Complexity: O(log n) with path compression
int DisjointSet::FindSet(int x)
{	
	if (x != parent[x] )
		parent[x] = FindSet(parent[x]); //path compression
	return parent[x];
}

//connect two sets contain x and y
//Complexity: O(1) with path compression and union by rank
void DisjointSet::Union(int x, int y)
{
	int xroot = FindSet(x);
	int yroot = FindSet(y);

	//check if the element are in the same set
	if (xroot == yroot)
		return;

	// Attach smaller rank tree under root of high rank tree 
   // (Union by Rank) 
	if (rank[xroot] < rank[yroot]) {
		parent[xroot] = yroot;
		setSize[yroot] += setSize[xroot];
	}
	else if (rank[xroot] > rank[yroot]) {
		parent[yroot] = xroot;
		setSize[xroot] += setSize[yroot];
	}

	// If ranks are same, then make one as root and increment 
   // its rank by one 
	else{
		parent[yroot] = xroot;
		rank[xroot] ++;
		setSize[xroot] += setSize[yroot];
	}
}

//return the number of element in a set
int DisjointSet::sizeOfSet(int i)
{
	return setSize[FindSet(i)];
}

//check if two elements already in the same set
bool DisjointSet::sameSet(int x, int y)
{
	return FindSet(x) == FindSet(y);
}
