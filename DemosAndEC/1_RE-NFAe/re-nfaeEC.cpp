#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*  Complete all ** parts */

//==============================================
//  CS421 RE to NFA-e extra credit by: ** 
//===============================================

// Each transition within a machine
struct transition
{
  int start;    // start state
  char arrow;   // what to see on an arrow
  int end;      // next state
};

// NFA can store up to 10 machines.  
// Each machine is a vector of transitions.
vector<transition> NFA[10];

/* ALGORITHM:
   You will read the re.txt file to create initial 
   component machines and store these machines into NFA.
   You will then ask the user what operation they want
   to perform on the already created machines.
   As a new machine is created, add it to NFA.
   Repeat.
   NFA will be output to nfa-e.txt in the end.
*/  

 

// ------------- Put your utility functions here --------------------
      
// ** Such as display and copy functions for machines

// ------------- Machine processing functions follow -----------

void processConcat()
{ int M1, M2; // machine numbers 

  cout << "Enter number of the first machine:"; cin >> M1; 
  cout << "Enter number of the second machine:"; cin >> M2; 

  if (M1 == M2) { 
    cout << "Concatenating with itself..." << endl;
    cout << "copying the machine first ...." << endl;
    // ** Copy the machine with new state numbers and display it  (***)
    // The copy should be treated as M2
    }

  vector<transition> M; // the new machine to create and add to NFA

  // ** For the new machine M to add to NFA:     
     // - add M1 transitions and M2 transitions. 
     // - add a transition from M1's end to M2's start.

  // ** Display the new concatenated machine M.
  // ** Add M to NFA.

} // end of concat
// (***) It would be good to write a copy machine function
// which creates a new machine with new state numbers

void processOr()
{ int M1, M2; // machine numbers

  cout << "Enter number of the first machine:"; cin >> M1; 
  cout << "Enter number of the second machine:"; cin >> M2; 

  if (M1 == M2) { // must be a different one from M1
    cout << "Enter differnt number for the second machine";  cin >> M2;}

  vector<transition> M; // the new machine to create and add to NFA

  // ** For the new machine M to add to NFA:     
     // - create a new start state. 
     // - create a new final state.
     // - add a transition from new start to M1 start.
     // - add a transition from new start to M2 start.
     // - add M1 transitions and M2 transitions. 
     // - add a transition from M1's end to new final.
     // - add a transition from M2's end to new final.

  // ** Display the machine M.
  // ** Add the machine M to NFA
}// end of OR 


void processStar()
{ int M1;  // machine number

  cout << "Enter number of the machine:"; cin >> M1; 

  vector<transition> M; // the new machine to create and add to NFA

  // ** For the new machine M to add to NFA:
    // - create a new start state. 
    // - create a new final state.
    // - add a transition from the new start to M1's start.
    // - add M1 transitions. 
    // - add a transition (back) from M1's end to M1's start.
    // - add a transition from M1's end to the new final.
    // - add a transition (skip) from the new start to the new final.

  // ** Display the machine M.
  // ** Add the machine M to NFA.
} // end of STAR

void processPlus()
{ int M1;  // machine number

  cout << "Enter number of the machine:"; cin >> M1; 

  vector<transition> M; // the new machine to create and add to NFA

  // ** For the new machine M to add to NFA:
    // - create a new start state. 
    // - create a new final state.
    // - add a transition from new start to M1's start.
    // - add M1 transitions. 
    // - add a transition (back) from M1's end to M1's start.
    // - add a transition from M1's end to the new final.

  // ** Display the machine M.
  // ** Add the machine M to NFA.
} // end of PLUS


// ------------ Test Driver ---------------------

int main()
{
 cout << "This program will transform regular expressions into NFA-e" << endl;
 cout << "But it is done interactively by asking you to apply operators" << endl;
 cout << "to component machines." << endl;

 ifstream fin ("re.txt", ios::in);  // components come from re.txt
 char c;  
 transition trs;

 cout << "Reading in the components from re.txt...." << endl;
 while (fin >> c)
    { 
      // ** Build a transition (trs) for arrow label c.
      // ** Display the transition.
      // ** Add it to NFA as a machine.
    }  
  fin.close();
 // -- finished creating component machines

 // -- It then asks the user to combine machines.  
 // -- Combined machines' transitions will be added to NFA.

  char A;  // user choice
  while (A != 'n')
    {
      cout << "---- MENU -----" << endl;
      cout << "* for a machine" << endl;
      cout << "+ for a machine" << endl;
      cout << "| for two machines" << endl;
      cout << "- for appending two machines" << endl;
      cout << "n to quit" << endl;
      cin >> A;
      
      if (A == '*') processStar();
      else if (A == '+') processPlus();
      else if (A == '|') processOr();
      else if (A == '-') processConcat();
      
    }// end of interaction

  cout << "Outputting all machines to nfa-e.txt... " << endl;
  ofstream fout ("nfa-e.txt", ios::out);
  // ** Send all NFA contents to the output file which
  //    is created new each time.

} // the end
