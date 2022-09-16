#include<iostream>
#include<string>
using namespace std;

#include<queue>
 // include queue.h or equivalent such as <queue>

//----------------------------------------------
// CS421 HW1 
// Write a generator in C++ for L = {x | x is any combination of a's and b's}.
// Your name: Ryan Ringer
//----------------------------------------------

// Copy the recognizer function here from the other file.
bool recognizer(string s)
{
	int size = s.size();

        for(int i = 0; i < size; i++)
        {
        	if(s[i] != 'a' && s[i] != 'b') return false;
        }
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
    queue<string> language;
    queue<string> toBeAppended;
    string alphabet = "abc";
    string temp = "";
    string nestedTemp = "";
    int queueSize = alphabet.size();
    int itCounter = 0;
    string choice = "n";

    for (int i = 0; i < queueSize; i++) {
        temp = alphabet[i];
        if (recognizer(temp)) {
            language.push(temp);
            cout << temp << endl;
        }
    }
    
    if(language.size() > 0)
        while (true) {
            cout << "Continue with one more character? (y/n):";
            cin >> choice;
            if (choice != "y" && choice != "yes") {
                return 1;
            }
            /*if (itCounter >= 20) {
                cout << "Continue for 20 more, or until next character (whichever comes last)? (y/n):";
                cin >> choice;
                if (choice != "y" && choice != "yes") {
                   return 1;
                }
            }*/
            queueSize = language.size();
            while (!language.empty()) {
                temp = language.front();
                language.pop();
                for (int i = 0; i < alphabet.size(); i++) {
                    nestedTemp = temp + alphabet[i];
                    if (recognizer(nestedTemp)) {
                        toBeAppended.push(nestedTemp);
                        cout << nestedTemp << endl;
                        itCounter++;
                    }
                    else {

                    }
                    
                }
            }
            language = toBeAppended;
            while (!toBeAppended.empty()) {
                toBeAppended.pop();
            }
        }


    return 0;
}
