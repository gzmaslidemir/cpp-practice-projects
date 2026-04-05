#include <iostream>
#include <string>
#include <cctype> //for isupper, toupper, tolower
using namespace std;

int main() {
    
  // ANSI Color codes
string RED = "\033[31m";
string  MAGENTA = "\033[35m";
string RESET = "\033[0m";

string userString;

    //get user input
    cout << "Please enter a string: "<< endl; 
    getline(cin, userString);
    
    cout << endl; //spacing
    
    //Reversing
    userString = string(userString.rbegin(), userString.rend());
    
    cout << "The reverse of your string is: " << endl;
    cout << RED << userString << RESET << endl;
    
    cout << endl; //Spacing
    
    cout << "Your string with reversed cases: " << endl;

    // Toggle the case of each letter
    for (char &c : userString) {
        if (isupper(c)) {
            c = tolower(c);
        } else if (islower(c)) {
            c = toupper(c);
        }
    }
        cout << MAGENTA << userString << RESET << endl;
       
        return 0;
    }
    
 
    

