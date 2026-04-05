#include <iostream>
using namespace std;

int main()
{
    int countA = 0; // Initialize counters to 0 to avoid garbage value
    int countB = 0;
    int countC = 0;
    int countD = 0;
    int countF = 0;
    
    char grade;
    
    //Prompt the user
    cout << "Enter the letter grades (EOF to end): " << endl;
    
    while (cin >> grade) { //Read grades until EOF
        
        switch (grade) {
            
            case 'A':
            case 'a':
                countA++; //Increment for the counter
                break;
                
            case 'B':
            case 'b':
                countB++;
                break;
                
            case 'C':
            case 'c':
                countC++;
                break;
                
            case 'D':
            case 'd':
                countD++;
                break;
            
            case 'F':
            case 'f':  
                countF++;
                break;
            
            // Ignore non-letter inputs
            case '\n':
            case '\t':
            case ' ':
                break;
                
            default:
                cout << "Invalid grade entered." << endl;
        }
    }
    
    //Display grade summary
    cout << "\nGrade Summary:\n";;
    cout << "A: " << countA << endl;
    cout << "B: " << countB << endl;
    cout << "C: " << countC << endl;
    cout << "D: " << countD << endl;
    cout << "F: " << countF << endl;
    
    return 0;
     
}
