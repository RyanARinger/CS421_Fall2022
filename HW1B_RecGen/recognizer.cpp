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
	int size = s.size();

	for(int i = 0; i < size; i++)
	{
		if(s[i] != 'a' && s[i] != 'b') return false;
	}
	return true;
}// end of recognizer

//main: Given a string (from E) cined from the user, pass it to
//      the recognizer function.
//      Cout "YES IN L" or "NO NOT IN L" depending on what was returned.
int main()
{

	string input = "";
	cout << "ENTER A STRING: ";

	while(cin >> input){	
		if(input == "1"){
			break;
		}
		if(recognizer(input)){
			cout << "YES IN L" << endl;
		}
		else{
			cout << "NO NOT IN L" << endl;
		}

		cout << "ENTER A STRING: ";
	}
    // feel free to put it in a loop 

}// end of main
