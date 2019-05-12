#include "BST.h"

//constructor
BST::BST()
{
	root = nullptr;
}

//destructor
//if destructor did not implement, the memory from heap will not be delete, become garbage -> create memory leak
BST::~BST()
{
	RemoveTree(root);
}


void BST::Insert(int v)
{
	AuxInsert(root, v);
}

//recursively insert node into the tree
void BST::AuxInsert(Node *&r, int v)
{
	if (r == nullptr) // if tree is empty, create new node and insert in tree
		r = new Node(v);

	else {
		if (v <= r->val)
			AuxInsert(r->left, v);

		else
			AuxInsert(r->right, v);
	}
}


void BST::RemoveTree(Node*&r)
{
	if (r == nullptr)
		return; // if tree is empty, exit out of the execution
	else {
		RemoveTree(r->left);
		RemoveTree(r->right);
		delete r;
		r = nullptr;
	}
}


void BST::InorderPrint()
{
	InorderPrintAux(root);
	cout << endl;
}

//recursively print inorder tree
//left, root, right
void BST::InorderPrintAux(Node*r)
{
	if (r == nullptr)
		return;

	else {
		InorderPrintAux(r->left);
		cout << r->val << " ";
		InorderPrintAux(r->right);
	}
}

//print tree in preorder
void BST::PreorderPrint()
{
	PreorderPrintAux(root);
	cout << endl;
}

//root, left, right
void BST::PreorderPrintAux(Node*r)
{
	if (r == nullptr)
		return;
	else {
		cout << r->val << " ";
		PreorderPrintAux(r->left);
		PreorderPrintAux(r->right);
	}
}

//print tree in postorder
void BST::PostOrderPrint()
{
	PostOrderPrintAux(root);
	cout << endl;
}

//left, right, root
void BST::PostOrderPrintAux(Node*r)
{
	if (r == nullptr)
		return;
	else {
		PostOrderPrintAux(r->left);
		PostOrderPrintAux(r->right);
		cout << r->val << " ";
	}
}


int BST::Sum()
{
	return RecursiveSum(root);
}

//return the sum of nodes in the tree recursively
int BST::RecursiveSum(Node*r)
{
	if (r == nullptr)
		return 0;
	else
		return r->val + RecursiveSum(r->left) + RecursiveSum(r->right);
}


int BST::NumNodes()
{
	return NumNodes(root);
}

//return the number of nodes in the tree recursively
int BST::NumNodes(Node*r)
{
	if (r == nullptr)
		return 0;
	else
		return 1 + NumNodes(r->left) + NumNodes(r->right);
}


int BST::NumLeaves()
{
	return NumLeaves(root);
}

//returns the number of leaves (node with no children) in a tree recursively
int BST::NumLeaves(Node*r)
{
	if (r == nullptr)
		return 0;
	if (r->left == nullptr && r->right == nullptr)
		return 1;
	else
		return NumLeaves(r->left) + NumLeaves(r->right);
}

//return the maximum value of the tree (non-recursively)
int BST::MaxValue()
{
	Node*r = root;
	if (r == nullptr) {
		cout << "Tree is empty" << endl;
	}
	else {
		while (r->right != nullptr) {
			r = r->right;
		}
		return r->val;
	}
}



int BST::MinValue()
{
	return MinValue(root);
}

//return the minimum value of the tree recursively
int BST::MinValue(Node*r)
{
	if (r == nullptr)
		return 0;
	if (r->left == nullptr)
		return r->val;
	else 
		return MinValue(r->left);
}


bool BST::Find(int v)
{
	return Find(v, root);
}

//recursively return true if v is in tree, false if not
bool BST::Find(int v, Node*r)
{
	if (r == nullptr)
		return false;
	if (v == r->val)
		return true;
	else {
		if (v < r->val)
			return Find(v, r->left);
		else
			return Find(v, r->right);
	}
}


int BST::Rank(int v)
{
	return Rank(v, root);
}

//recursively return the rank of a node in the tree
int BST::Rank(int v, Node*r)
{
	if (r == nullptr)
		return 0;
	if (v == r->val)
		return NumNodes(r->left);
	else {
		if (v < r->val)
			return Rank(v, r->left);
		else
			return 1 + NumNodes(r->left) + Rank(v, r->right);
	}
}



int BST::Range(int L, int R)
{
	return Range(L, R, root);
}

//recursively return number of nodes between L and R, (including L but not R)
int BST::Range(int L, int R, Node*r)
{
	if (r == nullptr)
		return 0;
	if (r->val >= L && r->val < R)
		//return 1 + Range(L,R,r->left) + Range(L,R,r->right);
		return Rank(R) - Rank(L);
	if (r->val < L)
		return Range(L, R, r->right);
	else 
		return Range(L, R, r->left);
}


int BST::Depth(int v)
{
	return Depth(v, root, 0);
}

//return the depth of a node recursively
int BST::Depth(int v, Node*r, int d)
{
	if (r == nullptr)
		return -1;
	if (v == r->val)
		return d;
	if (v < r->val)
		return Depth(v, r->left, d + 1);
	else
		return Depth(v, r->right, d + 1);
}


int BST::Height()
{
	return Height(root);
}


int BST::Height(Node*r)
{
	if (r == nullptr)
		return 0;
	else
		return 1 + max(Height(r->left), Height(r->right)); //return the node from top to bottom
		//return max(Height(r->left), Height(r->right)); //return the edges from root to the deepest node in tree
}
