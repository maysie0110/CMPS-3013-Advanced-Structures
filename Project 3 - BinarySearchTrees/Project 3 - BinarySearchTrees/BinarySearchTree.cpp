// CMPS 3013 - Advanced Structures
// Project #3: Empirical Study of Binary Search Tree
// 10/14/2018
//*************************************************************** 
// The program will create a random binary search tree.  
// It then performs the asymmetric deletion algorithm and symmetric deletion
// algorithm for 128 node tree and 256 node tree. In each case, the program
// will run 100 times, and 100,000 insertion/deletion pair for each run.
// The average IPL will be calculated.
// The program will print the result into output file (output.txt) 
// to be graph in Excel
//***************************************************************** 
/*
I have written the entire program as turned in and have not copied this code,
or parts of this code from the internet or another student.
Signature____________________
*/

#include<iostream>
#include<random>
#include"BST.h"

#define TREESIZE 256 //number of nodes in tree
#define VALUESIZE 32000 // This is what you mod by to get a random number.
#define INSDELPAIRS 100000

using namespace std;
int main() {

	//ASYMMETRIC DELETETION of 128 nodes tree
	// build a random tree of 128 nodes
	int N = 128;
	vector <long long> iplData(100, 0); //create a vector that store 100 values and set it to 0
	int iterator = 100; //run 100 times
	//randomly delete 1 node, then randomly insert a new node
	for (int count = 0; count < iterator; count++) { //collect data 100 times to average
		BST t(N);
		for (int i = 0; i < N; i++) {
			//insert random number in binary tree
			t.Insert(rand());
		}
		for (int i = 0; i < INSDELPAIRS; i++) {	//do 100,000 delete/insert pair for each run
			//run every 1000 pairs, get its IPL -> 100 IPL
			if (i % 1000 == 0) {
				iplData[i / 1000] += t.IPL(); //store it in a vector
			}
			t.RandDelInsPair(0); //doing Sdelete every time
		}
		//t gets destroyed here when it goes out of scope
	}
	cout << "Asymmetric deletion for 128 nodes" << endl;
	//find the average IPL
	for (int i = 0; i < iplData.size(); i++) {
		cout << iplData[i] / iterator << endl;
	}
	while (!iplData.empty()) {
		iplData.pop_back();
	}
	//------------------------------------------------------------//
	iplData.assign(100, 0); //reassign the vector 
	//SYMMETRIC deletion of 128 nodes tree
	for (int count = 0; count < iterator; count++) {
		BST t(N);
		for (int i = 0; i < N; i++) {//insert random number in binary tree
			t.Insert(rand());
		}
		for (int i = 0; i < INSDELPAIRS; i++) {	//do 100,000 delete/insert pair for each run
			//run every 1000 pairs, get its IPL -> 100 IPL
			if (i % 1000 == 0) {
				iplData[i / 1000] += t.IPL(); //store it in a vector
			}

			//alternate sdelete and pdelete to keep the tree balance
			if (i % 2 == 0) {
				t.RandDelInsPair(0); //doing Sdelete at even number
			}
			else
				t.RandDelInsPair(1); //doing Pdelete at odd number

		}//t gets destroyed here when it goes out of scope
	}
	cout << "------------------------------------------------" << endl;
	cout << "Symmetric delete for 128 nodes" << endl;
	//find the average IPL
	for (int i = 0; i < iplData.size(); i++) {
		cout << iplData[i] / iterator << endl;
	}
	while (!iplData.empty()) {
		iplData.pop_back();
	}

	//------------------------------------------------------------//
	//ASYMMETRIC DELETETION of 256 nodes tree
	iplData.assign(100, 0);

	for (int count = 0; count < iterator; count++) { //collect data 100 times to average
		BST t(TREESIZE);
		for (int i = 0; i < N; i++) {
			//insert random number in binary tree
			t.Insert(rand());
		}
		for (int i = 0; i < INSDELPAIRS; i++) {	//do 100,000 delete/insert pair for each run
			//run every 1000 pairs, get its IPL -> 100 IPL
			if (i % 1000 == 0) {
				iplData[i / 1000] += t.IPL(); //store it in a vector
			}
			t.RandDelInsPair(0); //doing Sdelete every time
		}
		//t gets destroyed here when it goes out of scope
	}
	cout << "Asymmetric deletion for 256 nodes" << endl;
	//find the average IPL
	for (int i = 0; i < iplData.size(); i++) {
		cout << iplData[i] / iterator << endl;
	}
	while (!iplData.empty()) {
		iplData.pop_back();
	}
	//------------------------------------------------------------//
	//SYMMETRIC deletion of 256 nodes tree
	iplData.assign(100, 0);
	for (int count = 0; count < iterator; count++) {
		BST t(TREESIZE);
		for (int i = 0; i < N; i++) {//insert random number in binary tree
			t.Insert(rand());
		}
		for (int i = 0; i < INSDELPAIRS; i++) {	//do 100,000 delete/insert pair for each run
			//run every 1000 pairs, get its IPL -> 100 IPL
			if (i % 1000 == 0) {
				iplData[i / 1000] += t.IPL(); //store it in a vector
			}

			//alternate sdelete and pdelete to keep the tree balance
			if (i % 2 == 0) {
				t.RandDelInsPair(0); //doing Sdelete at even number
			}
			else
				t.RandDelInsPair(1); //doing Pdelete at odd number

		}//t gets destroyed here when it goes out of scope
	}
	cout << "------------------------------------------------" << endl;
	cout << "Symmetric delete for 256 nodes" << endl;
	//find the average IPL
	for (int i = 0; i < iplData.size(); i++) {
		cout << iplData[i] / iterator << endl;
	}
	while (!iplData.empty()) {
		iplData.pop_back();
	}

	return 0;
}