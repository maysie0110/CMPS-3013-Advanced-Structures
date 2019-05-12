#include "BST.h"



BST::BST(int v)
{
	_size = v;
}


BST::~BST()
{
	_size = 0;
	valueList.clear();
	DestroyTree(_root);
}

//insert new node, adds it to the vector and increments size
void BST::Insert(int value)
{
	valueList.push_back(value); //update vector that hold the values exists in tree
	insert(_root, value);
}


void BST::insert(pTreeNode & r, int value)
{
	if (r == nullptr)
		r = new treeNode(value);
	else if (value < r->_key)
		insert(r->_left, value);
	else
		insert(r->_right, value);

	//_size++; //update size of tree

}

//Inorder tree walk printout.
void BST::Inorder()
{
	Inorder(_root);
	cout << endl;
}


void BST::Inorder(pTreeNode tree)
{
	if (tree == nullptr)
		return;
	else {
		Inorder(tree->_left);
		cout << tree->_key << " ";
		Inorder(tree->_right);
	}
}



void BST::Sdelete(int value)
{
	//update vector 
	for (auto it = valueList.begin(); it != valueList.end(); it++)
	{
		if (*it == value) {
			valueList.erase(it);
			goto sdelete;
		}
	}

sdelete:
	SdeleteAux(_root, value);
}

//recursively delete node from tree (successor delete)
//complexity : O(n)
void BST::SdeleteAux(pTreeNode &tree, int value)
{

	if (tree == nullptr)
		return;
	else if (value < tree->_key)
		return SdeleteAux(tree->_left, value);
	else if (value > tree->_key)
		return SdeleteAux(tree->_right, value);
	else {
		if (tree->_left == nullptr && tree->_right == nullptr) {
			delete tree;
			tree = nullptr;
			return;
		}
		else {
			if (tree->_left == nullptr) {//only 1 child on the right
				pTreeNode temp = tree->_right;
				delete tree;
				tree = temp;
				return;
			}
			if (tree->_right == nullptr) {//only 1 child on the left
				pTreeNode temp = tree->_left;
				delete tree;
				tree = temp;
				return;
			}
			else {//if node has more than 1 tree
				pTreeNode ptr;
				pTreeNode follow;

				ptr = tree->_right;
				follow = ptr;

				if (ptr->_left == nullptr) {
					tree->_right = ptr->_right;
					tree->_key = ptr->_key;
					delete ptr;
					return;
				}

				while (ptr->_left != nullptr) {
					follow = ptr;
					ptr = ptr->_left;
				}

				tree->_key = ptr->_key;

				if (ptr->_right != nullptr) {
					follow->_left = ptr->_right;
					delete ptr;
				}
				else {
					follow->_left = nullptr;
					delete ptr;
				}
			}
		}
	}
}


void BST::Pdelete(int value)
{
	//update vector 
	for (auto it = valueList.begin(); it != valueList.end(); it++)
	{
		if (*it == value) {
			valueList.erase(it);
			goto pdelete;
		}
	}
	
pdelete:
	PdeleteAux(_root, value);
}

//predecessor delete from tree
void BST::PdeleteAux(pTreeNode & tree, int v)
{
	if (tree == nullptr)
		return;
	else if (v < tree->_key)
		return PdeleteAux(tree->_left, v);
	else if (v > tree->_key)
		return PdeleteAux(tree->_right, v);
	else {
		//if the node found has no children
		if (tree->_left == nullptr && tree->_right == nullptr) {
			delete tree;
			tree = nullptr;
			return;
		}
		//if there is at least 1 child
		else {
			if (tree->_left == nullptr) {//only 1 child on the right
				pTreeNode temp = tree->_right;
				delete tree;
				tree = temp;
				return;
			}

			else if (tree->_right == nullptr) {//only 1 child on the left
				pTreeNode temp = tree->_left;
				delete tree;
				tree = temp;
				return;
			}
			else {//if node has more than 1 tree
				pTreeNode ptr;
				pTreeNode follow;

				ptr = tree->_left;
				follow = ptr;

				if (ptr->_right == nullptr) {
					tree->_left = ptr->_left;
					tree->_key = ptr->_key;
					delete ptr;
					return;
				}

				while (ptr->_right != nullptr) {
					follow = ptr;
					ptr = ptr->_right;
				}

				tree->_key = ptr->_key;

				if (ptr->_left != nullptr) {
					follow->_right = ptr->_left;
					delete ptr;
				}
				else {
					follow->_right = nullptr;
					delete ptr;
				}
			}
		}

	}
}

//delete node from tree
void BST::DestroyTree(pTreeNode &tree)
{
	if (tree == nullptr)
		return;
	else {
		DestroyTree(tree->_left);
		DestroyTree(tree->_right);
		delete tree;
		tree = nullptr;
	}

}

int BST::NumNodes()
{
	return NumNodes(_root);
}

//return the number of nodes in tree
int BST::NumNodes(pTreeNode tree)
{
	if (tree == nullptr)
		return 0;
	else
		return 1 + NumNodes(tree->_left) + NumNodes(tree->_right);
}

//randomly selects value in vector, delete it from tree
//and insert a new random value into vector and tree
//uses either Sdelete(1) or Pdelete(0)
void BST::RandDelInsPair(int dType)
{
	//randomly get an index of a value from the vector that holds all the values of the tree
	int randomIndex = rand() % valueList.size();

	//If dType is 0 use Sdelete otherwise use Pdelete
	if (dType == 0) {
		Sdelete(valueList[randomIndex]);
	}
	else
		Pdelete(valueList[randomIndex]);

	Insert(rand());
}

//calculate the internal path length
int BST::IPL()
{
	return iplAux(_root, 0);
}


int BST::iplAux(pTreeNode & tree, int depth)
{
	if (tree == nullptr)
		return 0;

	else
		return depth + iplAux(tree->_left, depth + 1) + iplAux(tree->_right, depth + 1);//keep recursive on the left subtree all the way to the end,
	// and then call recursive on the right subtree
}
