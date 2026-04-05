#include <iostream>
#include <iomanip> // for formatting output (e.g., salary precision)
using namespace std;

//struct 
struct employee {
    string name;
    int id;
    float salary;
};

//function prototype(s)

void displayEmployees(employee* arr, int numEmployees);

int main()
{
    int numEmployees;
    
    cout << "Enter the number of employees: ";
    cin >> numEmployees;
    
    // Dynamically allocate an array of employee struct on the heap
    employee* employees = new employee[numEmployees];
    
    //Input employee details
    for (int i = 0; i < numEmployees; i++) {
        cout << "Enter the details for employees " << i + 1 << ":" << endl;
        
        cout << "ID: ";
        cin >> employees[i].id;
        
        //Clear the input buffer before reading a full name
        cout << "Name: ";
        cin.ignore(1000, '\n');
        getline(cin, employees[i].name);
        
        cout << "Salary: ";
        cin >> employees[i].salary;
        
    }
    
    // Pass the dynamic array to a function for display
    displayEmployees(employees, numEmployees);
    
    delete[] employees;
    
    return 0;
    
}

//function defintion(s)
void displayEmployees(employee* arr, int numEmployees) {
    
    cout << "Employee Details: " << endl;
    cout << fixed << setprecision(2);
    
    for (int i = 0; i < numEmployees; i++) {
        
        cout << "Employee " << i + 1 << ":" << endl;
        cout << "ID: " << arr[i].id << endl;
        cout << "Name: " << arr[i].name << endl;
        cout << "Salary: $" << arr[i].salary << endl;
        cout << "-----------------------------" << endl;
    }
}
