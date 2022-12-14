#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: ** 5
//=====================================================

// --------- Two DFAs ---------------------------------
//q0 = 0
//q0q1 = 1
//qt = 2
//qy = 3
//qsa = 4
//qs = 5
//qc = 6
//q0qy = 7
// WORD DFA 
// Done by: ** Reinhold Kulick
// RE:   ** 
bool word(string s)
{

    int state = 0;
    int charpos = 0;
    while (s[charpos] != '\0')
    {

        if (state == 0 && s[charpos] == 't') // if we are in the start state and we read a t
            state = 2;// go to state 2 (qt)

        else if (state == 0 && ((s[charpos] == 'b') || (s[charpos] == 'g') || (s[charpos] == 'm') || (s[charpos] == 'p') || (s[charpos] == 'r') || (s[charpos] == 'n') || (s[charpos] == 'h') || (s[charpos] == 'k'))) // if we are in the start state and receive a consonant
            state = 3;// go to state 3 (qy)

        else if (state == 0 && ((s[charpos] == 'a') || (s[charpos] == 'e') || (s[charpos] == 'i') || (s[charpos] == 'o') || (s[charpos] == 'u') || (s[charpos] == 'E') || (s[charpos] == 'I'))) // if we are in the start state and we read a vowel
            state = 1;// go to state 1 (q0q1)

        else if (state == 0 && s[charpos] == 's')// if we are in the start state and we read an s
            state = 5;// go to state 5(qs)

        else if (state == 0 && ((s[charpos] == 'd') || (s[charpos] == 'w') || (s[charpos] == 'z') || (s[charpos] == 'j') || (s[charpos] == 'y')))// if we are in state one and we read in a d w z j or y
            state == 4; // go to state 4 (qsa)

        else if (state == 0 && s[charpos] == 'c')// if we are in the start state and we read in a c
            state = 6; // go to state 6 (qc)

        else if (state == 1 && ((s[charpos] == 'a') || (s[charpos] == 'e') || (s[charpos] == 'i') || (s[charpos] == 'o') || (s[charpos] == 'u') || (s[charpos] == 'E') || (s[charpos] == 'I'))) // we are in state one and receive a vowel
            state = 1;// remain at state 1 (q0q1)

        else if (state == 1 && ((s[charpos] == 'd') || (s[charpos] == 'w') || (s[charpos] == 'z') || (s[charpos] == 'j')))// if we are in state 1 and we read a d w z or j
            state = 4;// go to state 4(qsa)	

        else if (state == 1 && ((s[charpos] == 'b') || (s[charpos] == 'g') || (s[charpos] == 'm') || (s[charpos] == 'p') || (s[charpos] == 'r') || (s[charpos] == 'h') || (s[charpos] == 'k'))) // if we are in state one and we read in a b g m p r or h
            state = 3;// go to state 3 (qy)

        else if (state == 1 && s[charpos] == 'c')// if we are in state 1 and we read in a c
            state = 6;// go to state 6(qc)	

        else if (state == 1 && s[charpos] == 's')// if we are in state 1 and we read in an s
            state = 5;// go to state 5(qs)

        else if (state == 1 && s[charpos] == 'n')// if we are in state 1 and we read in an n
            state = 7;// go to state 7(q0qy)

        else if (state == 1 && s[charpos] == 't')// if we are in state 1 and we read in a t
            state = 2;// go to state 2(qt)

        else if (state == 2 && s[charpos] == 's')// if we are in state 2 and we read in an s
            state = 4;// go to state 4(qsa)

        else if (state == 2 && ((s[charpos] == 'a') || (s[charpos] == 'e') || (s[charpos] == 'i') || (s[charpos] == 'o') || (s[charpos] == 'u') || (s[charpos] == 'E') || (s[charpos] == 'I'))) // we are in state 2 and receive a vowel
            state = 1;// go to state 1 (q0q1)

        else if (state == 3 && ((s[charpos] == 'a') || (s[charpos] == 'e') || (s[charpos] == 'i') || (s[charpos] == 'o') || (s[charpos] == 'u') || (s[charpos] == 'E') || (s[charpos] == 'I'))) // we are in state 3 and receive a vowel
            state = 1;// go to state 1 (q0q1)

        else if (state == 3 && s[charpos] == 'y') //if we are in state 3 and receive a y
            state = 4;// go to state 4 (qsa)

        else if (state == 4 && ((s[charpos] == 'a') || (s[charpos] == 'e') || (s[charpos] == 'i') || (s[charpos] == 'o') || (s[charpos] == 'u') || (s[charpos] == 'y') || (s[charpos] == 'E') || (s[charpos] == 'I'))) // we are in state 4 and receive a vowel or a y
            state = 1;// go to state 1 (q0q1)

        else if (state == 5 && ((s[charpos] == 'a') || (s[charpos] == 'e') || (s[charpos] == 'i') || (s[charpos] == 'o') || (s[charpos] == 'u') || (s[charpos] == 'E') || (s[charpos] == 'I'))) // we are in state 5 and receive a vowel 
            state = 1;// go to state 1 (q0q1)

        else if (state == 5 && s[charpos] == 'h') //if we are in state 5 and receive a h
            state = 4;// go to state 4 (qsa)

        else if (state == 6 && s[charpos] == 'h') //if we are in state 6 and receive a h
            state = 4;// go to state 4 (qsa)

        else if (state == 7 && ((s[charpos] == 'a') || (s[charpos] == 'e') || (s[charpos] == 'i') || (s[charpos] == 'o') || (s[charpos] == 'u') || (s[charpos] == 'E') || (s[charpos] == 'I'))) // we are in state 7 and receive a vowel 
            state = 1;// go to state 1 (q0q1)

        else if (state == 7 && ((s[charpos] == 'b') || (s[charpos] == 'g') || (s[charpos] == 'm') || (s[charpos] == 'p') || (s[charpos] == 'r') || (s[charpos] == 'n') || (s[charpos] == 'h') || (s[charpos] == 'k'))) // if we are in state 7 and receive a consonant
            state = 3;// go to state 3 (qy)

        else if (state == 7 && ((s[charpos] == 'd') || (s[charpos] == 'w') || (s[charpos] == 'z') || (s[charpos] == 'j') || (s[charpos] == 'y')))// if we are in state one and we read in a d w z j or y
            state == 4; // go to state 4 (qsa)

        else if (state == 7 && s[charpos] == 's') //if we are in state 7 and receive an s
            state = 5;// go to state 5 (qs)

        else if (state == 7 && s[charpos] == 't') //if we are in state 6 and receive a h
            state = 2;// go to state 4 (qt)

        else if (state == 7 && s[charpos] == 'c') //if we are in state 6 and receive a h
            state = 6;// go to state 4 (qc)

        else {
            return false;
        }
        charpos++;
    }//end of while

  // where did I end up????
    if (state == 0 || state == 1 || state == 7) return true;  // end in a final state
    else return false;
}

// PERIOD DFA 
// Done by: ** Reinhold Kulick
bool period(string s)
{  // complete this **
    int state = 0;// state counter
    int charpos = 0;// char positon counter
    while (s[charpos] != '\0') // while there is a character in the string that is not the end string character
    {
        if (state == 0 && s[charpos] == '.') // if we are in the start state and we read a t
            state = 1;// go to state 2 (qt)
        else if (state == 1)// if we are in the final state and we read in a character 
            return false;// fail
        charpos++;// itterates char position so that we traverse the string
    }// end of while
    if (state == 1)// if we are in a final state
        return true;// success
    return false;// if we get here without being in a final state
}// end of period

// ------ Three  Tables -------------------------------------

// TABLES Done by: Ben Dominguez & Ryan Ringer

const int ROWS = 19;        //number of unique reserved words provided in the reservedwords.txt file
const int COLS = 2;         //one column to store the reserved word, one to store the string representation of the token name associated with it
const int NUMTOKENS = 30;   //lenght of the tokenName array

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype { ERROR, EOFM, PERIOD, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR, WORD1, WORD2 };

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[NUMTOKENS] = { "ERROR", "EOFM", "PERIOD", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR", "WORD1", "WORD2" };

//table made up of reservedWords and their tokenType in string form
string reservedWords[ROWS][COLS] = {
    {"masu", "VERB"},
    {"masen", "VERBNNEG"},
    {"mashita", "VERBPAST"},
    {"masendeshita", "VERBPAST"},
    {"desu", "IS"},
    {"deshita", "WAS"},
    {"o", "OBJEST"},
    {"wa", "SUBJECT"},
    {"ni", "DESTINATION"},
    {"watashi", "PRONOUN"},
    {"anata", "PRONOUN"},
    {"kare", "PRONOUN"},
    {"kanojo", "PRONOUN"},
    {"sore", "PRONOUN"},
    {"mata", "CONNECTOR"},
    {"soshite", "CONNECTOR"},
    {"shikashi", "CONNECTOR"},
    {"dakara", "CONNECTOR"},
    {"eofm", "EOFM"}
};


// ------------ Scanner and Driver ----------------------- 

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Ryan Ringer & Ben Dominguez
int scanner(tokentype& tt, string& w)
{
    // ** Grab the next word from the file via fin
    fin >> w;
    // 1. If it is eofm, return right now.   
    if (w == "eofm") {
        tt = EOFM;
        return 0;
    }

    /*  **
    2. Call the token functions (word and period)
       one after another (if-then-else).
       Generate a lexical error message if both DFAs failed.
       Let the tokentype be ERROR in that case.

    3. If it was a word,
       check against the reservedwords list.
       If not reserved, tokentype is WORD1 or WORD2
       decided based on the last character.


    4. Return the token type & string  (pass by reference)
    */
    // if the token is not a word
    if (!word(w)) {
        //check if token is a period
        if (period(w)) { //is token is a period set type PERIOD
            tt = PERIOD;
            return 0;
        }//if token is not a word or a period, display lexical error message, set tokentype to ERROR
        else {
            cout << "LEXICAL ERROR: Invalid string passes no DFA token criteria" << endl;
            tt = ERROR;
            return 1;
        }
    }
    //if token is a word, search reservedWords table for current token
    for (int i = 0; i < ROWS; i++) {
        if (w == reservedWords[i][0]) { //if token is found in reservedWords table
            for (int j = 0; j < NUMTOKENS; j++) {//find associated token type in tokenName array
                if (reservedWords[i][1] == tokenName[j]) {//if token type is found in the tokenName array
                    tt = (tokentype)j; //use the index of the array element to find enumerable tokenType
                    return 0;
                }
            }
        }
    }
    // if word not found in reserved words list determine if WORD1 or WORD2
    if (w[w.size() - 1] == 'E' || w[w.size() - 1] == 'I') {//check the last char in the string, if it is either 'I' or 'E'
        tt = WORD2;         //token type is WORD2
    }
    else {                  //otherwise WORD1
        tt = WORD1;
    }

    return 0;
}//the end of scanner



// The temporary test driver to just call the scanner repeatedly  
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!! 
// Done by:  Louis
int main()
{
    tokentype thetype;
    string theword;
    string filename;

    cout << "Enter the input file name: ";
    cin >> filename;

    fin.open(filename.c_str());

    // the loop continues until eofm is returned.
    while (true)
    {
        scanner(thetype, theword);  // call the scanner which sets
                                    // the arguments  
        if (theword == "eofm") break;  // stop now

        cout << "Type is:" << tokenName[thetype] << endl;
        cout << "Word is:" << theword << endl << endl;
    }

    cout << "End of file is encountered." << endl;
    fin.close();


}// end
