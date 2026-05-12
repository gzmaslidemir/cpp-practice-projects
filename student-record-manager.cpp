#include <iostream>
#include <string>
using namespace std;

//Structs
struct Student {
    int id;
    string name;
    float gpa;
};

struct Node {
    Student student;
    Node* next;
};

//Function Prototypes (samples included, you may change naming structures)
void addStudent(Node*& head, int id, const string& name, float gpa);
bool removeStudent(Node*& head, int id);
Student* searchStudent(Node* head, int id);
void printStudents(Node* head);
void freeList(Node*& head);
void printMenu();
Student getStudentInput();

int main() {
    
    Node* head = nullptr;  //start with empty list
    bool running = true; //controls the menu loop
    
    cout << "Student Record Manager\n";
    
    while (running)
    {
        printMenu();
        
        int choice;
        cin >> choice;
        
        if(choice == 1)
        {
            //get student data and add it to the list
            Student s = getStudentInput();
            addStudent(head, s.id, s.name, s.gpa);
            
        } 
        else if (choice == 2)
        {
            //Remove a student by ID
            int id;
            cout << "Enter ID to remove: ";
            cin >> id;
            
            if(!removeStudent(head, id))
            {
                cout << "Student not found.\n";
            }
        }
        
        else if (choice == 3)
        {
            //Search for a student by ID
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            
            Student* s = searchStudent(head, id);
            if (s)
            {
                cout << "Found: " << s->name << ",GPA: " << s->gpa << endl;
            }
            else {
                cout << "Student not found.";
            }
            
        }
        else if (choice == 4)
        {
            //Print all students in the linked list
            printStudents(head);
        }
        else if (choice == 0)
        {
          running = false;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }
    //Free all dynamically allocated nodes before ending the program 
    freeList(head);
   
    cout << "Goodbye!\n";
   
    return 0;
}

void addStudent(Node*& head, int id, const string& name, float gpa) 
{ 
    Node* newNode = new Node; //Create a new Node
    
    newNode->student.id = id;
    newNode->student.name = name;
    newNode->student.gpa = gpa;
    newNode->next = nullptr; //last node
    
    //if list is empty -> new node becomes head
    if(head == nullptr) 
    {
        head = newNode;
        return;
    }
    //otherwise go to the end of the list
    Node* current = head;
    while(current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
}
//Remove a student from the list by ID
bool removeStudent(Node*& head, int id){
    //empty list check
    if (head == nullptr) {
        
        return false;
    }
    if (head->student.id == id) //the head node matches the ID
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    
    Node* current = head; //find the node before the one we want to delete
    while(current->next != nullptr && current->next->student.id != id) {
        current = current->next;
    }
    if (current->next == nullptr) { //if the student was not found
        return false;
    }
    //Remove the matching node
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    return true;
    
}
//Search for a student by ID
Student* searchStudent(Node* head, int id)
{
    Node* current = head;
    
    while(current != nullptr) //Traverse the list until the student is found
    {
       if (current->student.id == id)
       {
           return &(current->student);
       }   
       current = current->next;
    }
    
    return nullptr; //Return nullptr if not found

}
//Print every student in the list
void printStudents(Node* head) 
{
    Node* current = head;
    
    while(current != nullptr) //Traverse and print each student record
    {
       cout << "ID: " << current->student.id
       <<", Name" << current->student.name 
       << ", GPA " << current->student.gpa << endl;
       
       current = current->next;
    }
}
//Delete all nodes to free memory   
void freeList(Node*& head) 
{
    Node* current = head;
    
    while (current != nullptr) //Traverse and print each student record
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    
    head = nullptr; //Avoid dangling pointer
}
//Display the menu options
void printMenu() 
{
    cout << "\nMenu:\n";
    cout << "1.Add Student\n";
    cout << "2.Remove Student\n";
    cout << "3.Search Student\n";
    cout << "4.Print All Students\n";
    cout << "0.Exit\n";
    cout << "Enter your choice: ";
    
}
//Get Student information from the user
Student getStudentInput()
{
    Student s;
    
    cout << "Enter ID: ";
    cin >> s.id;
    cin.ignore(); //clear newline before getline
    
    cout << "Enter Name: ";
    getline(cin, s.name);
    
    cout << "Enter GPA: ";
    cin >> s.gpa;
    
    return s;
}    
