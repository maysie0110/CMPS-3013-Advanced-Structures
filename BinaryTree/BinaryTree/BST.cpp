#include "BST.h"



BST::BST()
{
	root = nullptr;
}

//tree destructor
BST::~BST()
{
	RemoveTree(root);
}


// This public function inserts a new value into the trees
void BST::insert(int v)
{
	insertAUX(v, root);
}


void BST::insertAUX(int v, Node *& r)
{
	if (r == nullptr) {
		r = new Node(v);
	}
	else {
		if (v < r->val)
			insertAUX(v, r->left);
		else
			insertAUX(v, r->right);
	}
}

//inorder traversal (left,node,right)
void BST::printAUX(Node * r)
{
	if (r != nullptr) {

		//printAUX(r->left); //pre order
		//cout << r->val << " ";
		//printAUX(r->right);

		printAUX(r->left); //inorder traversal
		cout << r->val << " ";
		printAUX(r->right);

		
		//post order traversal 
		/*printAUX(r->left);
		printAUX(r->right);
		cout << r->val << " ";*/
	
		//use RPN - reverse polish notation
		
	}
	//cout << endl;
}


void BST::print()
{
	printAUX(root);
}

// O(n)
int BST::Sum()
{
	int result = Sum(root);
	return result;
}

// O(n)
int BST::Sum(Node* r)
{
	if (r == nullptr) {
		return 0;
	}
	else
		return (r->val + Sum(r->left) + Sum(r->right));
}

// O(n)
int BST::NumNodes()
{		
	return NumNodes(root);
}

// O(n)
int BST::NumNodes(Node* r)
{
	if (r) { //if r != 0 then it's true
		return 1 + NumNodes(r->left) + NumNodes(r->right);
	}
	else //if r == 0 
		return 0;
}


int BST::MaxValue()
{
	if (root == nullptr) {
		cout << "Tree is empty! " << endl;
	}
	else {
		Node * r = root;
		while (r->right != nullptr) {
			r = r->right;
		}

		return r->val;
	}
}

//return the number of leaves in a tree
int BST::NumLeaves()
{
	return NumLeaves(root);
}

//O(n)
int BST::NumLeaves(Node * r)
{
	if (r == nullptr) { //if node is nullptr, tree is empty, return 0
		return 0;
	}
	//if left and right child nodes are nullptr, it is the leaf node, return 1
	if (r->left == nullptr && r->right == nullptr)
		return 1;
	//recursively call the next node and check left and right node
	//num. of leaf = leaf of left subtree + leaf of right subtree
	else
		return NumLeaves(r->left) + NumLeaves(r->right);
}

//non-recursively
//return the rank of a node in the tree. (number of nodes < value given)
int BST::Rank(int v/*, Node * r*/)
{
	//non-recursively
	/*
	int rank = 0;
	Node* r = root;

	while (r != nullptr) {
		//if the given value is less than the val at root, continue to traverse left
		if (v < r->val) {
			r = r->left;
		}
		//if value greater than the value at root,count the root + size of the left subtree,
		//continue to traverse right
		else if (v > r->val) {
			rank += 1 + NumNodes(r->left);
			r = r->right;
		}
		//if the value is found in tree, return the size in the left subtree
		else
			return rank + NumNodes(r->left);
	}
	return -1; //Not found in the tree
	*/
	return Rank(root, v);
}


//recursively return the rank of a node in the tree 
int BST::Rank(Node*r, int v)
{
	if (r == nullptr)
		return 0;
	if (v == r->val)
		return NumNodes(r->left);
	if (v < r->val)
		return Rank(r->left, v);
	else if (v > r->val)
		return 1 + NumNodes(r->left) + Rank(r->right, v);
}
//return number of nodes between L and R 
int BST::Range(int L, int R)
{
	
	return Range(L, R, root);
}

//return number of nodes between L and R (include L but not R)
int BST::Range(int L, int R, Node *r)
{
	if (r == nullptr) {
		return 0;
	}
	if (L <= R) { //if first number if low limit, and second number is high limit
		//check if current nodes is in range (include L but not R)
		if (r->val >= L && r->val < R)
			return 1 + Range(L, R, r->left) + Range(L, R, r->right);
		else if (r->val < L) {//if current node's value is smaller than low range
			return Range(L, R, r->right);
		}
		else //if current node's value is greater or equal to high range
			return Range(L, R, r->left);
	}
	else { //if first number if high limit, and second number is low limit
		if (r->val >= R && r->val < L)
			return 1 + Range(L, R, r->left) + Range(L, R, r->right);
		else if (r->val < R) {//if current node's value is smaller than low range
			return Range(L, R, r->right);
		}
		else //if current node's value is greater or equal to high range
			return Range(L, R, r->left);
	}
}

//height is the worst depth in the tree
int BST::Height()
{
	return Height(root);
}


int BST::Height(Node * r)
{
	if (r == nullptr) {
		return 0;
	}
	else
		return 1 + max(Height(r->left), Height(r->right));
}


//non recursive, call private function
int BST::Depth(int v)
{
	return Depth(root,v,0);
}

//recursively return the depth of the node in BST Tree
int BST::Depth(Node *r, int v, int d)
{
	if (r == nullptr)
		//v is not in the tree
		return -1;

	if (v == r->val)
		return d;

	if (v < r->val) 
		return Depth(r->left, v, d + 1); //DO NOT use d++ (it will change the value of d)
	
	else
		return Depth(r->right, v, d + 1);
}



//returns the internal path length of the tree
int BST::IPL()
{
	return IPL(root,0);
}

//recursively returns the sum of depths of all nodes in tree
int BST::IPL(Node *r, int depth)
{
	if (r == nullptr)
		return 0;

	//if (r->left == nullptr && r->right == nullptr)
	//	return depth;
	else
		return depth + IPL(r->left, depth + 1) + IPL(r->right, depth + 1);//keep recursive on the left subtree all the way to the end,
	// and then call recursive on the right subtree
}


int BST::printLevels()
{
	// TODO: Add your implementation code here.
	return 0;
}


void BST::RemoveTree(Node* &r) //inorder deletion of entire tree
{
	if (r == nullptr)
		return;
	else {
		RemoveTree(r->left);
		RemoveTree(r->right);
		delete r;
		r = nullptr;
	}
}

void BST::Delete(int v)
{
	DeleteAux(root,v);
}


void BST::DeleteAux(Node*&r, int v)
{
	//case 1: when tree is empty
	if (r == nullptr)
		return;
	
	else { //keep searching for the value in the tree
		if (v > r->val)
			DeleteAux(r->right, v);
		else if (v < r->val)
			DeleteAux(r->left, v);
		else {//find the value
			//case 2: if the node found has no children
			if (r->right == nullptr && r->left == nullptr) {
				delete r;
				r = nullptr;
			}
			
			//if there are at least 1 child 
			else {
				Node * temp; //create temporaty node
				if (r->right == nullptr){// if only right child is nullptr
					temp = r->left;
					delete r;
					r = temp;
					return;
				}
				else if (r->left == nullptr) {//if only left child is nullptr
					temp = r->right;
					delete r;
					r = temp;
					return;
				}
				else { //if there are more than 1 child
					
					Node *ptr;
					Node *follower; //to track the successor
					//find successor
					ptr = r->right; 
					follower = ptr;

					if (ptr->left == nullptr) {
						r->right = ptr->right;
						r->val = ptr->val;
						delete ptr;
						return;
					}

					while (ptr->left != nullptr) {
						follower = ptr;
						ptr = ptr->left;
					}

					r->val = ptr->val;

					if (ptr->right != nullptr) {
						follower->left = ptr->right;
						delete ptr;
					}
					else {
						follower->left = nullptr;
						delete ptr;
					}
				}
			}

		}
	}
}
