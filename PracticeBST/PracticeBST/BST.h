#pragma once
#include<iostream>
#include<algorithm>
using namespace std;
class BST
{
	struct Node {
		int val;
		Node * left;
		Node * right;
		Node(int v) : val(v), left(nullptr), right(nullptr) {} 
		//parameterized constructor
		Node(int v, Node*l, Node*r) : val(v), left(l), right(r) {}
	};
	Node * root;
public:
	BST();
	~BST();
	void Insert(int v);
	void InorderPrint();
	void PreorderPrint();
	void PostOrderPrint();
	int Sum();
	int NumNodes();
	int NumLeaves();
	int MaxValue();
	int MinValue();
private:
	void AuxInsert(Node*&r, int v);
	void RemoveTree(Node*&r);
	void InorderPrintAux(Node*r);
	void PreorderPrintAux(Node*r);
	void PostOrderPrintAux(Node*r);
	int RecursiveSum(Node*r);
	int NumNodes(Node*r);
	int NumLeaves(Node*r);
	int MinValue(Node*r);
public:
	bool Find(int v);
private:
	bool Find(int v, Node*r);
public:
	int Rank(int v);
private:
	int Rank(int v, Node*r);
public:
	int Range(int L, int R);
private:
	int Range(int L, int R, Node*r);
public:
	int Depth(int v);
private:
	int Depth(int v, Node*r, int d);
public:
	int Height();
private:
	int Height(Node*r);
};

