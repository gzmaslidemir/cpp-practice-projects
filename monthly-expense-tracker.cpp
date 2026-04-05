#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    cout << "Welcome to the Montly Expense Tracker!" << "\n" ;
    
    //Start with a budget of $1000 for the month
    int budget = 1000;
    
    //Prompt the user to enter the amounts for three different expenses
    int rent, insurance, bills;
    
    cout << "\nEnter your rent expense: ";
    cin >> rent;
    
    cout << "Enter your insurance expense: ";
    cin >> insurance;
    
    cout << "Enter your bills expense: ";
    cin >> bills;
    
    
    //Calculate Remaining budget
    int remaining = budget - (rent + insurance + bills);
    
   
   //Decision
    if (remaining > 0) {
        cout << "\nYou have " << remaining << " dollars left" << endl;
    }    
    
    else if (remaining < 0) {   
        cout << "\nOpps! You have overspent by $" << abs(remaining) << "." << endl;
    }
    
    else { //remaining == 0
        cout << "\nYou've used up your budget!"  << endl;
    }
    
    return 0;
    
}   
