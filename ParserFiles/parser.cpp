#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

/* INSTRUCTION:  Complete all ** parts.
   You may use any method to connect this file to scanner.cpp
   that you had written.
  e.g. You can copy scanner.cpp here by:
          cp ../ScannerFiles/scanner.cpp .
       and then append the two files into one:
          cat scanner.cpp parser.cpp > myparser.cpp
*/

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
enum tokentype {
    ERROR,
    EOFM,
    PERIOD,
    VERB,
    VERBNEG,
    VERBPAST,
    VERBPASTNEG,
    IS,
    WAS,
    OBJECT,
    SUBJECT,
    DESTINATION,
    PRONOUN,
    CONNECTOR,
    WORD1,
    WORD2
};

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[NUMTOKENS] = {
    "ERROR",
    "EOFM",
    "PERIOD",
    "VERB",
    "VERBNEG",
    "VERBPAST",
    "VERBPASTNEG",
    "IS",
    "WAS",
    "OBJECT",
    "SUBJECT",
    "DESTINATION",
    "PRONOUN",
    "CONNECTOR",
    "WORD1",
    "WORD2"
};

//table made up of reservedWords and their tokenType in string form
string reservedWords[ROWS][COLS] = {
    {"masu", "VERB"},
    {"masen", "VERBNNEG"},
    {"mashita", "VERBPAST"},
    {"masendeshita", "VERBPAST"},
    {"desu", "IS"},
    {"deshita", "WAS"},
    {"o", "OBJECT"},
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
ofstream fout;

bool doTracer = true;
bool errorCorrection = false;
string message = "";

void printMessage() {
    if (doTracer) {
        cout << message << endl;
    }
}

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Ryan Ringer & Ben Dominguez
int scanner(tokentype& tt, string& w)
{
    // ** Grab the next word from the file via fin
    fin >> w;
    message = "Scanner called using word: " + w;
    printMessage();
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

//=================================================
// File parser.cpp written by Group Number: 5
//=================================================

tokentype saved_token;
string saved_lexeme;
bool token_available = false;
string filename;

// ----- Four Utility Functions and Globals -----------------------------------

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  

// Type of error: Match Error
// Done by: Renhold Kulick (fstream by Ryan Ringer)
void syntaxerror1(string savedlexeme, tokentype token_type) {
    string error = "MATCH SYNTAX ERROR: expected " + tokenName[token_type] + " but got " + savedlexeme + "\n";
    cout << error;
    fout << error;
    if(!errorCorrection) exit(1);
    //exit(1); //this is a real thing apparantly
}
// Type of error: Parser Error
// Done by: Reinhold Kulick (fstream by Ryan Ringer)
void syntaxerror2(string savedlexeme, string expected) {
    string error = "PARSER SYNTAX ERROR : unexpected \"" + savedlexeme + "\" found in parser function " + expected + "\n";
    cout << error;
    fout << error;
    exit(1);
}

// Type of error: Scanner lexical error
// Done by: Ryan Ringer
void scannerError(string lexeme) {
    string error = "LEXICAL ERROR: Invalid string " + lexeme + " passes no DFA token criteria\n";
    cout << error;
    fout << error;
    //exit(1);
}


// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme

// Purpose: Grab the next token from the iput string
// Done by: Ryan Ringer
tokentype next_token() {
    if (!token_available) {
        scanner(saved_token, saved_lexeme);

        token_available = true;

        if (saved_token == ERROR) {
            scannerError(saved_lexeme); //which error in this case?
        }
    }
    return saved_token;
}

// Purpose: Match an expected tokentype to a read in token type
// Done by: Ryan Ringer
bool match(tokentype expected) {
    string answer;
    if (next_token() != expected) {
        syntaxerror1(saved_lexeme, expected);
        if (!errorCorrection) {
            return false;
        }
        else {
            cout << "(Skip or Replace?) S/R: ";
            cin >> answer;
            if (answer == "S" || answer == "s") { //skip
                //cout << "Skipping \n" << saved_lexeme << "\n and testing next token" << endl;
                scanner(saved_token, saved_lexeme);
                return match(expected);
            }
            else if (answer == "R" || answer == "r") { //replace
                //do nothing for error case and replace
            }
            else {
                cout << "invalid input, killing correction" << endl;
                return false;
                //exit(1);
            }
        }
    }
    cout << "Matched " << tokenName[expected] << endl;
    token_available = false;
    return true;
}

// ----- RDP functions - one per non-term -------------------

// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

/*
1 <story> ::= <s> { <s> }
2 <s> ::= [CONNECTOR] <noun> SUBJECT <afterSubject>
3 <afterSubject> ::= <verb> <tense> PERIOD | <noun> <afterNoun>
4 <afterNoun> ::= <be> PERIOD  | DESTINATION <verb> <tense> PERIOD | OBJECT <afterObject>
5 <afterObject> ::= [ <noun> DESTINATION ] <verb> <tense> PERIOD
6 <noun> ::= WORD1 | PRONOUN
7 <verb> ::= WORD2
8 <be> ::=   IS | WAS
9 <tense> ::= VERBPAST  | VERBPASTNEG | VERB | VERBNEG
*/


//prototypes used to avoid reorderng functions. See code after main()
void story();
void s();
void afterSubject();
void afterNoun();
void afterObject();
void noun();
void verb();
void be();
void tense();


//----------- Driver ---------------------------

// The new test driver to start the parser
// Done by: Ryan Ringer
int main()
{
    /*string answer;

    cout << "Tracing? Y/N: ";
    cin >> answer;
    if (answer == "N" || answer == "n") {
        doTracer = false;
    }
    else if (answer == "Y" || answer == "y") {
        doTracer = true;
    }
    else {
        cout << "invalid input, tracing is on" << endl;
    }

    cout << "Error completion assumption? Y/N: ";
    cin >> answer;
    if (answer == "N" || answer == "n") {
        errorCorrection = false;
    }
    else if (answer == "Y" || answer == "y") {
        errorCorrection = true;
    }
    else {
        cout << "invalid input, error correction is off" << endl;
    }*/

    cout << "Enter the input file name: ";
    cin >> filename;
    fin.open(filename.c_str());
    fout.open("errors.txt");

    //** calls the <story> to start parsing
    story();
    //** closes the input file 
    fin.close();
    fout.close();

}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions



// Grammar: <story> ::= <s> { <s> }
// Done by: Ryan Ringer, Ben Dominguez, Reinhold Kulick
void story() {
    message = "Processing <story>";
    printMessage();
    s();
    while (true) {
        switch (next_token()) { // this is the same as a single if/else statement so we do not need to call syntaxError2() in the default
        case CONNECTOR:
        case WORD1:
        case PRONOUN:
            s();
            break;

        default:
            return;
        }

    }
}

// Grammar: <s> ::= [CONNECTOR] <noun> SUBJECT <afterSubject>
// Done by: Ryan Ringer, Ben Dominguez, Reinhold Kulick
void s() {
    message = "Processing <s>";
    printMessage();
    if (next_token() == CONNECTOR) {
        match(CONNECTOR);
    }
    noun();
    match(SUBJECT);
    afterSubject();
}

// Grammar: <afterSubject> ::= <verb> <tense> PERIOD | <noun> <afterNoun>
// Done by: Ryan Ringer, Ben Dominguez, Reinhold Kulick
void afterSubject() {
    message = "Processing <afterSubject>";
    printMessage();
    switch (next_token()) {
    case WORD2:
        verb();
        tense();
        match(PERIOD);
        break;

    case WORD1:
    case PRONOUN: //cascade
        noun();
        afterNoun();
        break;

    default: //syntax error
        syntaxerror2(saved_lexeme, "<afterSubject>");
        return;
    }
}

// Grammar: <afterNoun> ::= <be> PERIOD  | DESTINATION <verb> <tense> PERIOD | OBJECT <afterObject>
// Done by: Ryan Ringer, Ben Dominguez, Reinhold Kulick
void afterNoun() {
    message = "Processing <afterNoun>";
    switch (next_token()) {
    case IS:
    case WAS:
        be();
        match(PERIOD);
        break;

    case DESTINATION:
        match(DESTINATION);
        verb();
        tense();
        match(PERIOD);
        break;

    case OBJECT:
        match(OBJECT);
        afterObject();
        break;

    default: //syntax error
        syntaxerror2(saved_lexeme, "<afterNoun>");
        return;
    }
}

// Grammar: <afterObject> ::= [ <noun> DESTINATION ] <verb> <tense> PERIOD
// Done by: Ryan Ringer, Ben Dominguez, Reinhold Kulick
void afterObject() {
    message = "Processing <afterObject>";
    printMessage();
    if (next_token() == WORD1 || next_token() == PRONOUN) {
        noun();
        match(DESTINATION);
    }
    verb();
    tense();
    match(PERIOD);
}

// Grammar: <noun> ::= WORD1 | PRONOUN
// Done by: Ryan Ringer, Ben Dominguez, Reinhold Kulick
void noun() {
    message = "Processing <noun>";
    printMessage();
    switch (next_token()) {
    case WORD1:
        match(WORD1);
        break;
    case PRONOUN:
        match(PRONOUN);
        break;
    default:
        syntaxerror2(saved_lexeme, "<noun>");
        break;
    }
}

// Grammar: <verb> ::= WORD2
// Done by: Ryan Ringer, Ben Dominguez, Reinhold Kulick
void verb() {
    message = "Processing <verb>";
    printMessage();
    match(WORD2);
}

// Grammar: <be> ::=   IS | WAS
// Done by: Ryan Ringer, Ben Dominguez, Reinhold Kulick
void be() {
    message = "Processing <be>";
    printMessage();
    switch (next_token()) {
    case IS:
        match(IS);
        break;
    case WAS:
        match(WAS);
        break;
    default:
        syntaxerror2(saved_lexeme, "<be>");
        break;

    }
}

// Grammar: <tense> ::= VERBPAST  | VERBPASTNEG | VERB | VERBNEG
// Done by: Ryan Ringer, Ben Dominguez, Reinhold Kulick
void tense() {
    message = "Processing <tense>";
    printMessage();
    switch (next_token()) {
    case VERBPAST:
        match(VERBPAST);
        break;
    case VERBPASTNEG:
        match(VERBPASTNEG);
        break;
    case VERB:
        match(VERB);
        break;
    case VERBNEG:
        match(VERBNEG);
        break;
    default:
        syntaxerror2(saved_lexeme, "<tense>");
        break;
    }
}
