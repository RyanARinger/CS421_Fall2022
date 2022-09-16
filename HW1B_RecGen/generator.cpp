#include<iostream>
#include<string>
using namespace std;

#include<queue>
 // include queue.h or equivalent such as <queue>

//----------------------------------------------
// CS421 HW1 
// Write a generator in C++ for L = {x | x is any combination of a's and b's}.
// Your name: **
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
{ **
  
  while(true)
    {
        ** // generate a string
	** // if the recognizer says true, display it 
    }// end of while

}// end of main
