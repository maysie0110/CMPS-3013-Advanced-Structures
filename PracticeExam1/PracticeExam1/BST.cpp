#include "BST.h"

BST::BST()
{
	root = nullptr;
}

//implement destructor to avoid memory leak
BST::~BST()
{
	RemoveTree(root);
}

//recursively delete every node in tree
void BST::RemoveTree(Node*&r)
{
	if (r == nullptr) //if tree is empty, do nothing
		return;
	else {
		RemoveTree(r->left);
		RemoveTree(r->right);
		delete r;
		r = nullptr;
	}
}


void BST::insert(int v)
{
	insertAux(root, v);
}

//recursively insert node into tree (organized)
void BST::insertAux(Node*&r, int v)
{
	if (r == nullptr) {//if tree is empty
		//create a new node and insert it in the tree
		r = new Node(v);
	}
	else {
		if (v < r->val)
			insertAux(r->left, v);
		else
			insertAux(r->right, v);
	}
}


void BST::Inorder()
{
	InorderAux(root);
	cout << endl;
}


void BST::Preorder()
{
	PreorderAux(root);
	cout << endl;
}


void BST::Postorder()
{
	PostorderAux(root);
	cout << endl;
}

//left,root,right
void BST::InorderAux(Node*r)
{
	if (r!= nullptr){
		InorderAux(r->left);
		cout << r->val << " ";
		InorderAux(r->right);
	}
}

//root, left, right
void BST::PreorderAux(Node*r)
{
	if (r != nullptr){
		cout << r->val << " ";
		PreorderAux(r->left);
		PreorderAux(r->right);
	}
}

//left,right,root
void BST::PostorderAux(Node*r)
{
	if (r!= nullptr){
		PostorderAux(r->left);
		PostorderAux(r->right);
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
	return NumNodesAux(root);
}

//recursively return the total number of nodes in tree
int BST::NumNodesAux(Node*r)
{
	if (r == nullptr)
		return 0;
	else
		return 1 + NumNodesAux(r->left) + NumNodesAux(r->right);
}


int BST::NumLeaves()
{
	return NumLeavesAux(root);
}

//recursively return the total number of leaves in tree (node that has no children)
int BST::NumLeavesAux(Node*r)
{
	if (r == nullptr)
		return 0;
	if (r->left == nullptr && r->right == nullptr)
		return 1;
	else
		return NumLeavesAux(r->left) + NumLeavesAux(r->right);
}


//find min value of tree (non-recursively)
int BST::Min()
{
	Node * r = root;
	if (r == nullptr)
		return 0;
	else {
		while (r->left != nullptr)
			r = r->left;
		return r->val;
	}
}



int BST::Max()
{
	return MaxAux(root);
}

//recursively return the max value in tree
int BST::MaxAux(Node*r)
{
	if (r == nullptr)
		return 0;
	if (r->right == nullptr) //if there is no more right subtree or right child node
		return r->val;
	else 
		return MaxAux(r->right);
}


bool BST::Find(int v)
{
	return FindAux(v, root);
}

//recursively finding the value in tree (if present return true or 1, if not return false or 0)
bool BST::FindAux(int v, Node*r)
{
	if (r == nullptr)
		return false;
	if (v == r->val)
		return true;
	else if (v < r->val)
		return FindAux(v, r->left);
	else
		return FindAux(v, r->right);
}



int BST::Rank(int v)
{
	return RankAux(v, root);
}


int BST::RankAux(int v, Node*r)
{
	if (r == nullptr)
		return 0;
	if (v == r->val)
		return NumNodesAux(r->left);
	else if (v < r->val)
		return RankAux(v, r->left);
	else
		return 1 + NumNodesAux(r->left) + RankAux(v, r->right);
}



int BST::Range(int L, int R)
{
	return RangeAux(L, R, root);
}


int BST::RangeAux(int L, int R, Node*r)
{
	if (r == nullptr)
		return 0;
	if (r->val >= L && r->val < R)
		return 1 + RangeAux(L,R,r->left) + RangeAux(L,R,r->right);
	else if (r->val < L)
		return RangeAux(L, R, r->right);
	else
		return RangeAux(L, R, r->left);
}



int BST::Depth(int v)
{
	return Depth(v, root,0);
}


int BST::Depth(int v, Node*r, int d)
{
	if (r == nullptr) //if tree is empty
		return -1;
	if (v == r->val)
		return d;
	else if (v < r->val)
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
		return 1 + max(Height(r->left), Height(r->right));
}



int BST::IPL()
{
	return IPL(root,0);
}

//internal path length - the sum of distance between all nodes and the root
int BST::IPL(Node*r, int depth)
{
	if (r == nullptr)
		return 0;
	else
		return depth + IPL(r->left, depth + 1) + IPL(r->right, depth + 1);
}



void BST::printLevel()
{
	Node * r = root;
	if (root == nullptr)
		cout << "tree is empty" << endl;

	else {
		queue<Node*> myQueue;
		myQueue.push(r);
		while (!myQueue.empty()) {
			r = myQueue.front();
			myQueue.pop();
			if (r->left != nullptr)
				myQueue.push(r->left);
			if (r->right != nullptr)
				myQueue.push(r->right);
			cout << r->val << " ";
		}
	}
}



void BST::Delete(int v)
{
	return Delete(v, root);
}


void BST::Delete(int v,Node*&r)
{
	if (r == nullptr)
		return;

}
