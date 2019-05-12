#include<iostream>
#include<vector>
#include"BST.h"

using namespace std;

int main() {
	int a, b, c, d;
	BST Tree;
	vector<int> vec{15, 8, 30, 43, 22, 10, 9, 4, 72, 12};
	
	for (auto x : vec) {
		Tree.insert(x);
	}
	
	Tree.Inorder();
	Tree.Preorder();
	Tree.Postorder();
	cout << "Sum of nodes is: " << Tree.Sum() << endl;
	cout << "Number of nodes in tree is: " << Tree.NumNodes() << endl;
	cout << "Number of leaves in tree is: " << Tree.NumLeaves() << endl;
	cout << "Min value of tree is: " << Tree.Min() << endl;
	cout << "Max value of tree is: " << Tree.Max() << endl;
	cout << "Please enter a number you want to find: ";
	cin >> a;
	cout << Tree.Find(a) << endl;
	cout << "Rank of " << a << " is: " << Tree.Rank(a) << endl;

	cout << "Enter 2 numbers: " << endl;
	cin >> b >> c;
	cout << "Range is " << Tree.Range(b, c) << endl;

	cout << "Enter a number to find depth ";
	cin >> d;
	cout << "Depth is " << Tree.Depth(d) << endl;
	cout << "The height of tree is " << Tree.Height() << endl;
	cout << "IPL of tree is " << Tree.IPL() << endl;
	Tree.printLevel();
	system("pause");
	return 0;
}