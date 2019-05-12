#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class BST
{
	struct treeNode;
	typedef treeNode* pTreeNode;
	vector<int> valueList;// holds the values presently in the tree. Normally not in a tree
	int _size;//number of values in tree and in vector;
	struct treeNode {
		int _key;
		pTreeNode _left;
		pTreeNode _right;
		treeNode(int key) : _key(key), _left(nullptr), _right(nullptr) {}
	};
	pTreeNode _root;
	void insert(pTreeNode& r, int value);
	void Inorder(pTreeNode tree);
	void SdeleteAux(pTreeNode& tree, int value);
	void PdeleteAux(pTreeNode & tree, int v);
	void DestroyTree(pTreeNode &tree);
	int NumNodes(pTreeNode tree);
	int iplAux(pTreeNode & tree, int v);
public:
	BST(int);
	~BST();
	void Insert(int value);
	void Inorder();
	void Sdelete(int value);
	void Pdelete(int v);
	int NumNodes();
	void RandDelInsPair(int dType);
	int IPL();
};

