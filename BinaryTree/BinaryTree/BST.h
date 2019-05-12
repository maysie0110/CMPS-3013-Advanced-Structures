#pragma once
#include<iostream>
#include<algorithm>

using namespace std;
class BST
{
	struct Node {
		int val;
		Node* left;
		Node* right;
		Node(int v) : val(v), left(nullptr), right(nullptr) {}
	};

	Node* root;
public:
	BST();
	~BST();
	// This insert a new value into the trees
	void insert(int v);
	void print();
private:
	void insertAUX(int v, Node*& r);
	void printAUX(Node* r);
	int Sum(Node*);
	int NumNodes(Node *);
	int NumLeaves(Node*r);
	int Rank(Node*r, int v);
	int Range(int L, int R, Node *r);
	int Height(Node*r);
	int Depth(Node *r, int v, int d);
	int IPL(Node *r, int depth);
	void RemoveTree(Node*&r);
public:
	int Sum();
	int NumNodes();
	int MaxValue();
	int NumLeaves();
	int Rank(int val);
	int Range(int , int);
	int Height();
	int Depth( int v);
	int IPL();
	int printLevels();

	void Delete(int v);
private:
	void DeleteAux(Node*&r, int v);
};

