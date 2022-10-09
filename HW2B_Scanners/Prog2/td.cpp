#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

//--------------------------------------
// CS421 File td.cpp for HW2B Table-Driven Scanner
// Your name: Ryan Ringer 
//--------------------------------------

// Complete this to fit the HW2B specification - look for **
// Must have the same types of tracing couts as my demo program.


// info on each DFA
struct info
{
    string name;  // token name
    int startstate;
    int finalstate;
};

info DFAs[4];     // store up to 4 dfas' start and final

int TRS[10][4];

// ----- utility functions -----------------------

int readTables()
{
    ifstream fin("trs.txt", ios::in);
    ifstream fin2("dfas.txt", ios::in);

    string temp; //for each new string
    int cnt = 0; //starting counter for each field in the Infor struct
    int dfaCount = 0; //counter for the number of DFA's to be returned
    int state = 0; //current state
    int chr = 0; //current char
    //getline(fin2, temp,);

    stringstream stream(""); //use a stringstream to convert the strings to an int

    //for the TRS
    while (fin2 >> temp) { //while we have strings to read still
        stream << temp;
        switch (cnt) { //switch on the counter for fields. This determines what we just read
        case 0: //for the first field
            DFAs[dfaCount].name = temp; //store the name
            cnt++; //increment
            break;
        case 1: //for the second field
            stream >> DFAs[dfaCount].startstate; //convert the string to an int and store the value
            cnt++; //increment
            break;
        case 2: //for the third field
            stream >> DFAs[dfaCount].finalstate; //convert the string to an in and store the value
            cnt = 0; //reset the counter
            dfaCount++; //next element in the array
            break;
        }
        stream.clear();
        stream.str("");
    }

    //For the DFAs
    while (fin >> temp) { //while we are reading in strings
        //cout << chr << "," << state << " " << temp << endl;
        stream << temp;
        stream >> cnt; //convert the string to an int
        TRS[state][chr] = cnt; //store the int

        chr++; //prepare to read the next value, in this case for the letter after the one we just read
        if (chr > 3) { //if we are at the end of the row
            chr = 0; //reset the counter
            state++; //move to the next state
        }

        stream.clear();
        stream.str("");
    }

    return dfaCount; //return the number of dfas which we counted earlier
}

void displayTables(int numDFAs)
{

    for (int i = 0; i < numDFAs; i++) { // display each of the DFAs name, the start state, and the final state, all labeled
        cout << "Name: " << DFAs[i].name << " Start State: " << DFAs[i].startstate << " Final State: " << DFAs[i].finalstate << endl; //-
    }
    

    cout << "         a  b  c  d" << endl; //label line for the letters that each column represents
    for (int i = 0; i < 10; i++) { //for each state
        cout << "State " << i << ": "; // label it
        for (int j = 0; j < 4; j++) { //then for each column
            if (TRS[i][j] < 0) cout << "   "; //do not display negatives
            else
                cout << TRS[i][j] << "  "; // display the values with space after 
        }
        cout << endl; //endl endlessly
    }
}

bool accept(info dfa, string word)
{
    // ** Does the dfa accept the word?
    // Start with the start state of the DFA and
    // look up the next state in TRS for each char in word.
    // At the end of the word, make sure you are in the 
    // final state of the DFA.
    // Use a formula to convert chars to TRS col numbers.

    int state = dfa.startstate; //get the start state from the saved DFA
    int charpos = 0; // we'll use the same method for moving through the string that we used in Prog1 by incrementing an index counter
    int column; //variable for the column... duh

    while (word[charpos] != '\0') {
        //column is calculated by subtracting the ASCII value of lowercase 'a' from the char read in, this should give us a zero based index for accessing columns
        column = (int)word[charpos] - (int)'a'; 
        //debug output
        cout << "state is: " << state << " char is " << word[charpos] << " and the next state will be " << TRS[state][column] << endl;
        state = TRS[state][column]; //assign the new state to the state variable for later
        //cout << "Char is: " << word[charpos] << ", Moving to state : " << TRS[state][column] << endl;
        if (state < 0) return false; //bunk word token
        charpos++; //increment the counter
    }

    if (state == dfa.finalstate) return true; //if we're in the right state accept the string
    return false; //reject the string otherwise
}


int main()
{
    cout << "This is a table driven scanner. Needs trs.txt and dfas.txt." << endl;
    cout << "States are 0 to 9 and chars are a to d" << endl;
    
    bool accepted; //for output

    int numDFA = readTables(); // how many DFAs were read
    displayTables(numDFA);     // DISPLAY TABLES
    cout << ".....done reading tables...." << endl;

    string word;
    while (true)
    {
        accepted = false; //default is false
        cout << "@@Enter a string: ";
        cin >> word;
        // ** try the DFAs one by one and see 
        //      if the word is accepted
        //      if so, display the word and the token name
        // ** if no DFA does, generate a lexical error message.
        for (int i = 0; i < numDFA; i++) {
            if (accept(DFAs[i], word)) { //if the word is accepted in the DFA
                cout << "word is accepted as " << DFAs[i].name << endl; //output success
                accepted = true; //reset accepted to true
                break; //break out of the loop
            }
            cout << endl;
        }
        if (!accepted) { // means the 
            cout << "LEXICAL ERROR: Invalid string passes no DFA token criteria" << endl; //inform the user that their word is dumb and is not accepted
        }
        cout << endl << "do control-C to quit" << endl << endl;
    }
}//the end
