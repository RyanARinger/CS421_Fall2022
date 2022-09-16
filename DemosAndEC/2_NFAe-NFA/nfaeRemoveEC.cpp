#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

/* Complete all ** parts */ 

//========================================================
// CS421 Extra Credit by: **
// transform NFAe into NFA  (nfa-e.txt into nfa.txt)
//========================================================

// e.g. Output line 1 a 2 3  means 1 on a goes to 2 and 3

// Transitions of the NFAe are in a matrix called NFAe.  
// Rows: 10 states (0-9) and Columns: 5 chars (a-e). 
//                           e as epsilon is in column 4.
// Each slot of the matrix contains a vector of integers
// indicating the next states based on the row and column.

vector<int> NFAe[10][5]; 
int maxState;   // the highest state number used in NFAe


/* ALGORITHM:
   Read in nfa-e.txt into NFAe. 
   First, to handle Trs(s, e*...), for each state s,
   find all states you can go using only epsilons, and
   store them in E-Ends[s].
   Then, for each state-character pair: 
    - To handle Trs(s, e*c..), for each state s and char c,
      find all states you can go from E-Ends[s] on c, and
      store the destinations.
    - And then find all states you can go using only
      epsilons from the destinations, and
      store the them.
*/

// ----- put all of your utility functions here ---------------------------

// ** Such as display of vectors  and int-char conversion functions


// --------- Storing NFAe coming from the input file -----------------------

void buildnfae()
{ 
  int state; char c; int dest;  // inputs

  ifstream fin ("nfa-e.txt", ios::in);

  fin >> maxState; // states are 0 through this

  // ** store nfa-e.txt into NFAe by reading one line at a time

  // ** display the table nicely

  fin.close();
}

// ------------- Test Driver ----------------------


int main()
{ 

  buildnfae(); // NFAe has been created

  // ** open the output file nfa.txt 

  // For each possible state-char pair of NFAe,
  // we will compute Trs(state, e* char e*) to add to the output file as follows:

  vector<int> E_Ends[10];  // For each state (0-9), 
                     // stores all the states you can go to using only e-moves
  cout << "1) For each state, find all the states reachable using only e's" << endl; 
  for (int s = 0; s <= maxState;  s++)
    {
      // ** From state s, find all the states rechable using only e's
      // ** These should be stored in the E_Ends[s]
    }
  // ** display the E_Ends here clearly labelled.


  cout << "2) Computing Trs(s, e* ci e*) for each s-ci pair.." << endl;
  for (int s = 0; s <= maxState; s++)
     for (int ci = 0; ci < 4; ci++)  // ci 4 is epsilon so not used
      { 
       vector<int> Dests; // For the s-ci pair
                          // accumulates all the states you can go to from it.

        cout << "---------------------------------------" << endl;
        // ** Display the state and the char 

        // ** From s, get direct-on-ci destinations and add them to Dests 
        // ** Display Dests.

        // ** For each E_End[s], get (E_End, ci) destinations and add them to Dests
        // ** Display Dests.

        // ** For each destination in Dests, get E_Ends of it and add them to Dests
        // ** Display Dests.

        // ** Send the Final result for the (s, ci) pair (Dests) to the output file
    }// end of for

   cout << "NFA is in  nfa.txt .... " << endl;

   // ** close nfa.txt

}//the end

 
