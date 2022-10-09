#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//------------------------------------------------
// CS421 File fa.cpp for HW2B DFA->Scanner Function
// Your name: Ryan Ringer
//------------------------------------------------

// ** Change this to fit the HW2B specification - look for **
// ** Must have the same types of tracing couts as mytoken.
// ** Must complete the ** comments with RE

// ---------- DFAs follow -------------------------

//l = (s[charpos] == 'c' || s[charpos] == 'd')
//d = (s[charpos] == '8' || s[charpos] == '9')
//_ = (s[charpos] == '_')
//. = (s[charpos] == '.')

// MYTOKEN DFA done by professor as a sample
// This FA is for c d^+
bool mytoken(string s)
{ 
  int state = 0;
  int charpos = 0;

  cout << "Trying the mytoken machine..." << endl;  
 
  while (s[charpos] != '\0') 
    {
      cout << "current state: " << state << endl;
      cout << "character: " << s[charpos] << endl;
 
      if (state == 0 && s[charpos] == 'c')
          state = 1;
      else
          if (state == 1 && s[charpos] == 'd')
              state = 2;
          else
              if (state == 2 && s[charpos] == 'd')
                  state = 2;
              else
              {
                  cout << "I am stuck in state " << state << endl;
                  return(false);
              }
      charpos++;
    }//end of while

  // where did I end up????
  if (state == 2) return(true);  // end in a final state
   else return(false);
}// end of mytoken


// IDENT DFA 
// Trs(s0, l) = s1
// Trs(s1, l) = s1
// Trs(s1, d) = s1
// Trs(s1, _) = s1
// This FA is for RE: l(l|d|_)^*
bool ident_token(string s)
{
    int state = 0;
    int charpos = 0;
    cout << "Trying ident_token machine..." << endl;

    while (s[charpos] != '\0') {
        cout << "current state: " << state << endl;
        cout << "character: " << s[charpos] << endl;
        
        if (state == 0 && (s[charpos] == 'c' || s[charpos] == 'd')) {
            state = 1;
        }
        else {
            if (state == 1 && ((s[charpos] == 'c' || s[charpos] == 'd') || (s[charpos] == '8' || s[charpos] == '9') || s[charpos] == '_')) {
                state = 1;
            }
            else {
                cout << "I am stuck in state " << state << endl;
                return false;
            }
        }

        charpos++;

    }

    //final state == 1
    if (state == 1) return true;
    return false;

}//end of ident


// REAL DFA 
// Trs(s0, d) = s0
// Trs(s0, .) = s1
// Trs(s1, d) = s2
// Trs(s2, d) = s2
// This FA is for RE: d^*.d^+
bool real_token(string s)
{
    int state = 0;
    int charpos = 0;
    cout << "Trying real_token machine..." << endl;

    while (s[charpos] != '\0') {
        cout << "current state: " << state << endl;
        cout << "character: " << s[charpos] << endl;

        if (state == 0 && (s[charpos] == '8' || s[charpos] == '9')) {
            state = 0;
        }
        else if (state == 0 && s[charpos] == '.') {
            state = 1;
        }
        else {
            if (state == 1 && (s[charpos] == '8' || s[charpos] == '9')) {
                state = 2;
            }
            else {
                if (state == 2 && (s[charpos] == '8' || s[charpos] == '9')) {
                    state = 2;
                }
                else {
                    cout << "I am stuck in state " << state << endl;
                    return false;
                }
            }
        }

        charpos++;
    }

    //final state == 2
    if (state == 2) return true;
    return false;
}//end of real


//INT DFA 
// Trs(s0, d) = s1
// Trs(s1, d) = s1
// This FA is for RE: d^+
bool integer_token(string s)
{
    int state = 0;
    int charpos = 0;
    cout << "Trying real_token machine..." << endl;

    while (s[charpos] != '\0') {
        cout << "current state: " << state << endl;
        cout << "character: " << s[charpos] << endl;

        if (state == 0 && (s[charpos] == '8' || s[charpos] == '9')) {
            state = 1;
        }
        else {
            if (state == 1 && (s[charpos] == '8' || s[charpos] == '9')) {
                state = 1;
            }
            else {
                cout << "I am stuck in state " << state << endl;
                return false;
            }
        }

        charpos++;
    }

    //final state == 1
    if (state == 1) return true;
    return false;
}// end of int


// -----------------------------------------------------

enum tokentype {ERROR, MYTOKEN, IDENT, REAL, INT};
int scanner(tokentype& , string& );  // to be called by main
fstream fin;   // file stream to use

// The test-driver -- NO NEED TO CHANGE THIS
int main()
{ string fname;
  cout << "Enter the input file name:";
  cin >> fname; 

  fin.open( fname.c_str(), fstream::in);

  string tokens[5] = {"ERROR", "MYTOKEN", "IDENT", "REAL", "INT"};
  tokentype thetype;
  string theword; 

  while (true)  // keep on going 
    {
      scanner(thetype, theword);  // the paramers will be set by Scanner
      if (theword == "EOF") break;

      cout << ">>>>>Type is:" << tokens[thetype]  << endl;
    }

  cout << ">>>>>End of File encountered" << endl;  
  fin.close();
}// end of main 


// Scanner sets the_type and w - TO BE COMPLETED **
int scanner(tokentype& the_type, string& w)
{
  
  // This goes through all machines one by one on the input string w

  cout << endl;
  cout << ".....Scanner was called..." << endl;

  fin >> w;  // grab next word from fain.txt
  cout << ">>>>>Word is:" << w << endl;   

  if (mytoken(w))
    { the_type = MYTOKEN; }
  else if (ident_token(w)) {
      the_type = IDENT;
  }
  else if (real_token(w)) {
      the_type = REAL;
  }
  else if (integer_token(w)) {
      the_type = INT;
  }
  else //none of the FAs returned TRUE
    { cout << ">>>>>Lexical Error: The string is not in my language" << endl;
      the_type = ERROR; }

}//the very end of scanner




