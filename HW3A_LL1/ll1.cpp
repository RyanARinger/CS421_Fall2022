
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include"stack.h"  // ** can be removed
#include<vector>
#include<string>
using namespace std;

//---------------------------------------
// CS421 File ll1.cpp for HW3A LL1 Table-Driven Parser
// Your name: **
//---------------------------------------

// Complete this to fit the HW3A specification - look for **
// Must have the same types of tracing couts as my demo program.

// Feel free to use a stack class or use a vector
// to implement your stack.  The stack will contain characters.

vector<char> M[3][2];  // the table of rules 
                       // 3 rows for S, A, B
                       // 2 rows for 2, 3
       // Each slot contains a rule's right side
       // which is a vector of characters

//  ------- conversion functions ------------------------


// to convert non-terms S, A, B to table rows 0, 1, 2
int toRow(char C)
{
  //**  bunch of if then else
}

// to convert '2' and '3' to table columns 0 and 1 
int toCol(char c)
{
  // ** bunch of if then else
  //
  // when c is 2 return a 0
  // when c is 3 return a 1
}

// to convert row 0, 1, 2 to non-terms S, A and B
char toNonterm(int r)
{
  // ** bunch of if then else
}


// ** Then complete the following functions.-----------------------------

// to display a rule's rhs which is in vector V
void displayVector(vector<char> V) 
{
  // ** display V horizontally e.g. 2 A 2
}

// to read in the rules into M, make sure ; is not stored
void readrules()
{ 
  ifstream fin ("rules", ios::in);

  // For each line of "rules" (e.g. S  2 A 2 ;) 
  // The first char of a line determines the row of M
  // The second char of a line determine the column of M  
  // Note that each entry of M (the second char up to ;)
  // will be a vector representing 
  // the right hand side of a rule (rhs)
  

  // ** Display the table nicely  
  //    use toNonterm to show row labels (S, A, B)
  //    use displayVector for each content 

}

//  pushes V contents to the stack 
void addtostack(vector<char> V)
{  cout << "Pushing rhs of a rule to the stack." << endl;
  // **  be careful of the order
   // because 3 2 2 means 3 will be at the top of the stack
}

int main()
{ 
  readrules();  // M is filled and displayed 

  string ss;
  cout << "Enter a string made of 2's and/or 3's: ";
  cin >> ss;

  // ** push 'S' onto the stack to start

  cout << "Stack:";
  // ** display the stack vertically from top to bottom

  int i = 0;  // index for ss
  while (ss[i] != '\0')  // for each char of ss
    {
     // Based on ss[i] and 
     //    the top of stack, update the stack: 
     // ** note that empty stack will cause immediate failure  
     // ** note that top of stack terminal and ss[i] mismatching
     //    will cause immediate failure 
     // ** note that no entry in M for the top of stack (non-terminal)
     //    and ss[i] will cause immediate
     //    failure  (use toRow and toCol to look up M)
     // ** otherwise, addtoStack the M entry based on ss[i] and the top of stack 
    } // end of string


  // ** Here, check for success for failure based on stack empty or not

}// end of main
