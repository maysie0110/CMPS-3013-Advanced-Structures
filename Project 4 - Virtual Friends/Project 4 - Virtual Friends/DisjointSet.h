#pragma once
#include<vector>
#include<iostream>

using namespace std;

class DisjointSet
{
	vector<int> parent; 
	vector<int> rank;
	vector<int> setSize; //to keep track of number of element in set
	int FindSet(int x);  //Return the representative for the set containing element x.

public:
	DisjointSet(int num);//constructor
	~DisjointSet(); //destructor
	void Union(int x, int y);//Union the two sets represented by element x and y.
	int sizeOfSet(int x);//return the number of elements in a set
	bool sameSet(int i, int j);//check if elements are already in same set
};

