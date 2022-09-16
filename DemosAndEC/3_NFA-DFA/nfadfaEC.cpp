#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

/* Complete all ** parts */

//============================================
// CS421 Extra Credit by : **
// transform NFA into DFA  (nfa.txt into dfa.txt)
//=============================================

// States allowed are 0 through 9
// Arrows allowed are a through d
// Transitions of the NFA (10 states and 4 chars)
// Every slot contains a vector of destination states
vector<int> NFA[10][4];
int maxState;      // the highest state indicated in nfa.txt first line


// vector of new states in DFA (each state name is a string)
vector<string> DFAstates; 

/* ALGORITHM:
    Read in nfa.txt into NFA.
    Start with DFA state "0" 

    Grab a DFA state name.
    For each component of the state name:
      - For each possible arrow character,
        find all destinations in the NFA and 
        append the them to form a new DFA state name. 
      - Add the new name to DFAstates.
      - Output the DFA transition to dfa.txt
    Repeat above for more DFA state names.
*/ 

// ----- Your utility functions ----------------------------------------

// ** Such as display of state names and int-char converstion functions
// Note that I displayed < > around DFA state names 

// ------------- Storing the NFA ---------------------- 

// Reads nfa.txt to build the NFA data structure
void buildnfa()
{ 
  ifstream fin ("nfa.txt", ios::in);
  fin >> maxState; 

  // **** put code here *******************

  fin.close();
}

// --------------- Forming the DFA -------------------

// adds a state name to the vector DFAstates if it is new
void addNewState(string stateName)
{
  // *** put code here ****************
}

// append states to a state name without causing duplicates in the name
string appendtoName(string stateName, vector<int> states)
{
  // *** put code here to return a new state name string *******
} 

// Main Driver
int main()
{ 
  ofstream fout ("dfa.txt", ios::out);  // output stream

  cout << "Given your NFA in nfa.txt, this will produce the DFA in dfa.txt." << endl;
  cout << "State numbers must be 0 ... 9" << endl;
  cout << "Arrow labels can be anything from a .. e" << endl << endl;

  buildnfa();
  // NFA has been stored.

  addNewState("0");  // start with state "0" in DFAstates

  int x = 0; // index into DFAstates
  while (x < DFAstates.size() ) // for each DFA state
    { 
      // ** Display the current DFA state S (which is a string of component states)
      // ** For each possible arrow label al (a..d):
         string DS;  // a destination name for this pair 
         // ** For each component state cs of S,
             // - grab all Trs(cs, al) destinations from NFA and
             //   "appendtoName" the destinations to DS.
         // ** If DS has been formed for the S-al pair,     
                // display it and also send S, al and DS to dfa.txt
                // and DS is also added to DFAstates. 
    }// end of while
  cout << "No more states to process..." << endl;

  fout << "Any state with the original final state number is final" << endl;
  fout.close();

}//the end

 
