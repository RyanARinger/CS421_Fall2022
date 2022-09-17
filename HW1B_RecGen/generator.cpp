#include <iostream>
#include <queue>
#include <string>

using namespace std;

bool recognizer(string s) {
    int size = s.size();

    for (int i = 0; i < size; i++)
    {
        if (s[i] != 'a' && s[i] != 'b') return false;
    }
    return true;
}

int main()
{
    queue<string> language;
    queue<string> toBeAppended;
    string alphabet = "abc";
    string temp = "";
    string nestedTemp = "";
    int queueSize = alphabet.size();
    int itCounter = 0;
    string choice = "n";

    for (int i = 0; i < queueSize; i++) {
        temp = alphabet[i];
        if (recognizer(temp)) {
            language.push(temp);
            cout << temp << endl;
            itCounter++;
        }
    }
    
    if(language.size() > 0)
        while (true) {
            /*cout << "Continue with one more character? (y/n):";
            cin >> choice;
            if (choice != "y" && choice != "yes") {
                return 1;
            }*/
            queueSize = language.size();
            while (!language.empty()) {
                temp = language.front();
                language.pop();
                for (int i = 0; i < alphabet.size(); i++) {
                    if (itCounter >= 20) {
                        cout << "Continue for 20 more, or until next character (whichever comes last)? (y/n):";
                        cin >> choice;
                        if (choice != "y" && choice != "yes") {
                            return 1;
                        }
                        itCounter = 0;
                    }
                    nestedTemp = temp + alphabet[i];
                    if (recognizer(nestedTemp)) {
                        toBeAppended.push(nestedTemp);
                        cout << nestedTemp << endl;
                        itCounter++;
                    }
                    else {

                    }
                    
                }
            }
            language = toBeAppended;
            while (!toBeAppended.empty()) {
                toBeAppended.pop();
            }
        }


    return 0;
}

