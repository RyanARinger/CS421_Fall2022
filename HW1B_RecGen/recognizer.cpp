#include<iostream>
#include<string>
using namespace std;

//-------------------------------------------------------
// CS421 HW1 
// Write a recognizer in C++ for L = {x | x is any coombination of a's and b's}.
// Your name: Ryan Ringer
//-------------------------------------------------------

//  The recognizer function should return TRUE or FALSE 
//  checking each character
//  to make sure it is a or b.
bool recognizer(string s)
{
	//save the size of the string passed in
	int size = s.size();
	
	//loop through each character in the string
	for(int i = 0; i < size; i++)
	{
		//if not a or not b, return false
		if(s[i] != 'a' && s[i] != 'b') return false;
	}
	//else return true
	return true;
}// end of recognizer

//main: Given a string (from E) cined from the user, pass it to
//      the recognizer function.
//      Cout "YES IN L" or "NO NOT IN L" depending on what was returned.
int main()
{
	
	string input = ""; //container string for the user inputted string

	cout << "ENTER A STRING: ";//prompt
	
	//loop while valid input is read in
	while(cin >> input){	
		
		//check for specific flag to kill program
		if(input == "1"){
			//break out of function
			break;
		}
		if(recognizer(input)){ //if the string is valid
			cout << "YES IN L" << endl;
		}
		else{ //if the string is invalid
			cout << "NO NOT IN L" << endl;
		}

		cout << "ENTER A STRING: "; //prompt the user at the end of each cycle
	}
    // feel free to put it in a loop 

}// end of main
