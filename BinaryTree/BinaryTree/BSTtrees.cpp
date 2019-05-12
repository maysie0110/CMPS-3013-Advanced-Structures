//Practice code for Binary Search Tree
// CMPS 3013 - Advanced Structure
// 09/14/18


#include"BST.h"
#include<iostream>
#include<vector>

int main() {
	BST bt;
	srand(4); // same random of number

	int v,a,b,c,x;

	vector<int>D{10,5,4,6,2,3,9,7,8 };

	//for (int i = 1; i < 10000; i++) { //there are 99 numbers in the tree
	//	v = rand() % 10000;
	//	bt.insert(v); //insert random number between 0 - 99
	//}

	for (int i = 0; i < D.size(); i++) {
		bt.insert(D[i]);
	}
	bt.print();
	cout << endl;
	cout << "Sum is " << bt.Sum() << endl;
	cout << "Number of nodes is " << bt.NumNodes() << endl;
	cout << "The maximum node is " << bt.MaxValue() << endl;
	cout << "The number of leaves is " << bt.NumLeaves() << endl;

	cout << "Type a value (to find rank): ";
	cin >> v;
	cout << "Rank of value "<< v << " is " << bt.Rank(v) << endl;

	cout << "Type 2 nodes (to find range): ";
	cin >> a >> b;
	cout << "Range of " << a << " and " << b << " is " << bt.Range(a, b) << endl;

	cout << "Type a value (to find depth): ";
	cin >> c;
	cout << "Depth of " << c << " is " << bt.Depth(c) << endl;

	cout << "The height of the binary search tree is " << bt.Height() << endl;

	cout << "The IPL of the tree is " << bt.IPL() << endl;

	cout << "Enter a value to be delete: " << endl;
	cin >> x;
	bt.Delete(x);
	bt.print();

	system("pause");
	return 0;
}