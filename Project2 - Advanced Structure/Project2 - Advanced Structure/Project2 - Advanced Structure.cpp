// CMPS 3013 - Advanced Structures
// Project #2: Shipping
// 09/14/2018
//*************************************************************** 
// The program will read in letters for each case from an input file (data.dat)
// The goal of this program is to print the minimum number of stack of 
// containers for shipping seaport. Containers must be separated into 
// multiple stacks in which the top of each stacks can be loaded on the 
// ship in alphabetical order.
// The program will read the letter then check each stack to
// see if the current letter can be added. If yes, add it to stack.
// If not, add a new stack to the vector.
// The program will print the result into output file (output.txt)
// Complexity: O(N^2)
//***************************************************************** 
/*
I have written the entire program as turned in and have not copied this code,
or parts of this code from the internet or another student.
Signature____________________
*/

#include<vector>
#include<stack>
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int countCase = 1;
	stack <char> emptyStack;
	vector <stack <char>> vecStack; //vector of stacks of characters
	string prompt;
	cin >> prompt;
	while (prompt != "end") { //stop program when encounter word "end"

		//read in the data from input file and process it
		int i = 0;
		while( i < prompt.length()){
			
			// check each stack to see if the current letter can be added
			for (int j = 0; j < vecStack.size(); j++) {

				//if the current letter <= to the top of stack
				//add it to the end of stack
				if (prompt.at(i) <= vecStack[j].top()) {
					vecStack[j].push(prompt.at(i));

					//jump out of here and check the next letter
					goto update;
				}
			}
			//if none of the letters of top of stack can support the current letter
			//add a new empty stack into the vector
				vecStack.push_back(emptyStack);

			//the stack was added into the vector last will store the current letter
				vecStack[vecStack.size() - 1].push(prompt.at(i));

			update:
				i++; //check the next character
		}

		//print answer into an output file
		cout << "Case " << countCase << ": " << vecStack.size();
		countCase++;
		vecStack.clear();
		cout << endl;

		//read in the next case
		cin >> prompt;
	}
	return 0;
}
