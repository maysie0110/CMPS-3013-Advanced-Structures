// CMPS 3013 - Advanced Structures
// Project #4: UVA 11503 Virtual Friends
// 11/13/18
//*************************************************************** 
// The program will create a disjoint set class. The program will use 
// map in std library to store the string element and assign the index
// to performs the union of two sets of friends using disjoint set.
// Print out the number of friends in the same set of social network.
//***************************************************************** 
/*
I have written the entire program as turned in and have not copied this code,
or parts of this code from the internet or another student.
Signature____________________
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include"DisjointSet.h"

using namespace std;
int main() {

	int cases, F;
	char name1[20], name2[20];
	map<string, int> nameMap;
	
	//number of test cases
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		//the number of friendship formed
		cin >> F;
		DisjointSet SetNetwork(F * 2);

		int index = 0;
		int ans = 0;
		nameMap.clear();

		for (int i = 0; i < F; i++) {
			//read in names of 2 people who just become friends
			cin >> name1 >> name2;

			//check if name is already exist in storage
			//Complexity: O(log n)
			if (nameMap.find(name1) == nameMap.end()) {//name 1 is not in map yet
				nameMap[name1] = index++;
			}

			//Complexity: O(log n)
			if (nameMap.find(name2) == nameMap.end()) {	//name 2 is not in map yet
				nameMap[name2] = index++;
			}
			SetNetwork.Union(nameMap[name1], nameMap[name2]); 

	//Whenever a friendship is formed,print the number of people in the social network 
	//of the two people who have just become friends.
			ans = SetNetwork.sizeOfSet(nameMap[name1]);
			cout << ans << endl;
		}
	}
	return 0;
}