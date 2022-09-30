#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

//--------------------------------------
// CS421 File mat.cpp for HW2A Matrix Practice
// Your name: Ryan Ringer
//--------------------------------------

// the following can be changed and the rest of the code should work
int const R = 3;  // number of rows
int const C = 4;  // number of columns
int const VM = 3; // table entry (vector) length

vector<char>  T[R][C];  // 3 rows and 4 columns table for now 

// ------------------ Functions --------------------------------

int convert(char x)
{ 
  //** do a formula to convert m to 0, n to 1, o to 2 etc.
	//cout << "char code: " << (int)x - (int)'m' << endl;	
	return (int)x - (int)'m'; //subtract the ASCII value for 'm' from which ever character we recieve
	// this works cleaner than four if statements and is reasonably scalable to 'z' and even further
} 

int readTable()
{  int row, col;  // row and col numbers
   char col_c;     // column indicator
   ifstream fin ("lines.txt", ios::in);
 
  // Read in the file into T
   while (fin >> row) // next line of file
     {
       fin >> col_c; col = convert(col_c);  // convert to a slot number
       vector<char> v;  // a vector to fill
       char c; // one char from the file

       // ** Fill v with chars from the file (there are VM chars)
 	for(int i = 0; i < VM; i++){ // iterate once for every character expected in a string
		fin >> c; //read the character
		v.push_back(c); //push it onto the end of the vector
	}
       // ** Put  v in T[row][col]
        T[row][col] = v; //after the entire string is read, store into the matrix
     }//end of while
}

// Displays a vector or "---" if the vector is empty
void showVector(vector<char> v)
{ if (v.size() == 0)  // empty entry
    for (int i = 1; i <= VM; i++) cout << "- ";
  else
    // show the content of v separated by blanks (e.g. "m n o")
	for(int i = 0; i < VM; i++) cout << v[i] << " "; // output each character in the string followed by a space.
}

// Displays T as a table, separating entries with "|" 
void displayTable()
{
  // ** display T nicely labeled with row numbers (col numbers not needed)

	for(int i = 0; i < R; i++){ // for each row
		cout << i+1 << " "; //number the rows
		for(int j = 0; j < C; j++){ // for each column
			showVector(T[i][j]); //call the vector function
			cout << "|"; // put a bar between each string
		}
		cout << endl; //make a new line
	}

  //    by calling showVector 
}


// Driver
int main()
{
  cout << "Reading table from lines.txt..." << endl;
  readTable(); 
  displayTable();  
}//the end
