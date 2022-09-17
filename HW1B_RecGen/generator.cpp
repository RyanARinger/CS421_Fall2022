//this program was written in visual studio
#include <iostream>
#include <queue>
#include <string>

using namespace std;
** // include queue.h or equivalent such as <queue>

//----------------------------------------------
// CS421 HW1 
// Write a generator in C++ for L = {x | x is any combination of a's and b's}.
// Your name: Ryan Ringer
//----------------------------------------------

// Copy the recognizer function here from the other file.

//same recognizer function from the recognizer.cpp program
bool recognizer(string s) {
    int size = s.size(); //save the size of the passed string parameter

    //loop for the length of the string
    for (int i = 0; i < size; i++)
    {
		//if not a or b, then return false
        if (s[i] != 'a' && s[i] != 'b') return false;
    }
	//else return true if the string is valid
    return true;
}

// main: It should create each string over E = {a,b,c} systematically
//   (short to long) and pass each string to the recognizer function
//   created in Part a).  Hint: use a queue to generate strings
//   Only those strings for which the recognizer returned TRUE
//   should be displayed. 
//   Keeps on going until the queue overflows but the user can 
//   terminate the program with control-C 
//   after about 20 strings have been displayed.
int main()
{
	
    queue<string> language; //queue for the language, reset every iteration
    queue<string> toBeAppended; //queue for the inprogress processing of new strings in the language
    string alphabet = "abc"; //string that defines the three characters that make up the alphabet for the new language
    string temp = ""; //for storage.
    string nestedTemp = ""; //double storage
    int queueSize = alphabet.size(); //saving the size for the alphabet
    int itCounter = 0; //iteration counter for user input
    string choice = "n"; //string for the user's choice later on

	//test the initial alphabet to see which strings are valid
    for (int i = 0; i < queueSize; i++) {
        temp = alphabet[i]; //store each alphabet character for testing
        if (recognizer(temp)) { //if the char is valid
            language.push(temp); //add to the language queue
            cout << temp << endl; //output the string
            itCounter++; //incement the iteration counter
        }
    }

	//if one ore more strings passed the test, then begin generation
    if(language.size() > 0)
		//run forever
        while (true) {
            /*cout << "Continue with one more character? (y/n):";
            cin >> choice;
            if (choice != "y" && choice != "yes") {
                return 1;
            }*/
            queueSize = language.size(); // unused
			
            while (!language.empty()) { //while there are still strings to be checked
                temp = language.front(); //grab the first string
                language.pop(); //remove it from the queue
                for (int i = 0; i < alphabet.size(); i++) { //for each letter in the alphabet
                    if (itCounter >= 20) { // prompt user if iterations meet or exceed 20
                        cout << "Continue for 20 more, or until next character (whichever comes last)? (y/n):";
                        cin >> choice;
                        if (choice != "y" && choice != "yes") { //continue for another 20
                            return 1;
                        }
                        itCounter = 0;
                    }
					
                    nestedTemp = temp + alphabet[i]; //create a new temporary string with the current aplphabet character on the end
                    if (recognizer(nestedTemp)) { //if string is in language 
                        toBeAppended.push(nestedTemp); //add string to the temporary queue to be appended next time arround
                        cout << nestedTemp << endl; //output the passed string
                        itCounter++; //increment the iteration counter
                    }
                    else {
						// do nothing
                    }
                    
                }
            }
            language = toBeAppended; //assign the empty language queue to the new queue of valid strings
			
            while (!toBeAppended.empty()) { //while there are still elements in the queue
                toBeAppended.pop(); //remove an element
            }
        }

	//exit
    return 0;
}

