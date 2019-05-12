#include<iostream>
#include<vector>
#include"BST.h"

using namespace std;

int main() {
	BST tree;
	vector<int> vec{8, 9, 3, 5,4, 7, 10, 1, 15, 11};
	vector<int> v{ 56, 34, 90, 22, 57, 12, 5, 100, 39 };
	for (auto x : vec)
		tree.Insert(x);

	tree.InorderPrint();
	tree.PreorderPrint();
	tree.PostOrderPrint();

	cout << tree.Sum() << endl;
	cout << tree.NumNodes() << endl;
	cout << tree.NumLeaves() << endl;
	cout << tree.MaxValue() << endl;
	cout << tree.MinValue() << endl;

	int x, a, b;
	cout << "Enter a value: " << endl;
	cin >> x;
	//cout << tree.Find(x) << endl;
	cout << tree.Rank(x) << endl;

	/*cout << "enter 2 values: " << endl;
	cin >> a >> b;
	cout << tree.Range(a, b) << endl;*/

	cout << tree.Depth(x) << endl;
	cout << tree.Height() << endl;
	system("pause");
	return 0;
}