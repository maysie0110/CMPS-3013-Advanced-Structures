#pragma once
#include<iostream>
#include<queue>
#include <algorithm>
using namespace std;
class BST
{
	struct Node {
		int val;
		Node* left;
		Node *right;
		Node(int v) :val(v), left(nullptr), right(nullptr) {}
		Node(int v, Node* l, Node* r) : val(v), left(l), right(r) {}
	};
	Node* root;

public:
	BST();
	~BST();
	void insert(int v);
	void Inorder();
	void Preorder();
	void Postorder();
private:
	void RemoveTree(Node*&r);
	void insertAux(Node *&r, int v);
	void InorderAux(Node*r);
	void PreorderAux(Node*r);
	void PostorderAux(Node*r);
public:
	int Sum();
private:
	int RecursiveSum(Node*r);
public:
	int NumNodes();
private:
	int NumNodesAux(Node*r);
public:
	int NumLeaves();
private:
	int NumLeavesAux(Node*r);
public:
	int Min();
	int Max();
private:
	int MaxAux(Node*r);
public:
	bool Find(int v);
private:
	bool FindAux(int v, Node *r);
public:
	int Rank(int v);
private:
	int RankAux(int v, Node*r);
public:
	int Range(int L, int R);
private:
	int RangeAux(int L, int R, Node*r);
public:
	int Depth(int v);
private:
	int Depth(int v, Node*r, int d);
public:
	int Height();
private:
	int Height(Node*r);
public:
	int IPL();
private:
	int IPL(Node*r, int depth);
public:
	void printLevel();
	void Delete(int v);
private:
	void Delete(int v, Node*& r);
};

