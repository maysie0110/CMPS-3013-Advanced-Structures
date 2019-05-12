
//************************************************************** 
// May Trinh
// CMPS 3013 - Advanced Structures
// Project #1: Practice with vectors
// 09/02/2018
//*************************************************************** 
// This program's goal is to find the best location to minimize the total 
// distance to all of the relatives' houses.
// It will read in the data (integer values of number of test cases, 
// number of relatives and their street number) from input file (data.dat), 
// and store it in a vector.
// Using sort() in STL will sort the vector in ascending order. 
// The median (the value in the middle) will be the optimal house.
// To calculate the minimum sum of the distance, we take the sum of the
// difference between the last and the first value in the vector, then 
// increment and decrement accordingly.
// The program will print this sum into output file (output.txt)
// Complexity: O(n log n) [complexity of sort() function in STL]
//***************************************************************** 
/*
I have written the entire program as turned in and have not copied this code,
or parts of this code from the internet or another student.
Signature____________________
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases, numb;
	//int mid;
	int distance;
	cin >> cases;

	for (int i = 0; i < cases; i++) {
		cin >> numb;
		distance = 0;
		vector <int> H(numb); //declare a vector with the size of relatives

		for (int j = 0; j < numb; j++) {
			cin >> H[j]; //read the data and store it in the vector
		}
		
		//sort the data in the vector in ascending order
		sort(H.begin(), H.end()); //sort() in STL

		//process data in the vector
		//for the set number of 20,40,60,80. (the median is the optimal house)
		//Min. sum of distance (to the median)=x-20+x-40+60-x+80-x= 80-20+60-40
		int x = 0, y = numb - 1;
		while (x < y) {
			distance += H[y] - H[x];
			x++;
			y--;
		}
		
		cout << "Minimum sum of distance is " << distance << endl;

		/*
		// find the middle value (this will be the optimal house)
		mid = (H[0] + H[(numb- 1)]) / 2;
		cout << "Middle is " << mid << endl;
		distance = 0;
		// for each test case, calculate the summation of the distance between 
		// the optimal house with his relative using the formula dij = |si − sj |.
		for (auto x : H) {
			distance += abs(mid - x);
		}
		cout << "Minimum sum of distance is " << distance << endl;
		*/

		//check to see if the data is store in vector (print the entire vector)
		/*for (auto x : H) {
			cout << x << " ";
		}
		cout << endl;*/
	}
	return 0;
}

