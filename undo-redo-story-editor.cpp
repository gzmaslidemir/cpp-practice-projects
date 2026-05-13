#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main() {
    stack<string> undoStack;  // Stores words typed
    stack<string> redoStack;  // Stores words that were undone
    queue<string> finalStory; // Prints the final story in the correct order
   
    string word;

    cout << "Start typing your story one word at a time.\n";
    cout << "Type 'xUndo' to undo the last word, 'xRedo' to redo it, and 'xQuit' to finish.\n";
    
    //Input loop
    while (true) {
        cout << "> ";
        cin >> word;
        
        //Quit program
        if (word == "xQuit") {
            break;
        } 
        //Undo last word
        else if (word == "xUndo") { 
            if (!undoStack.empty()) {
                redoStack.push(undoStack.top());
                undoStack.pop();
                cout << "[Undo] Last word removed.\n";
                
            } else {
                cout << "[Undo] Nothing to undo.\n";
            }
        }
        //Redo last undone word
        else if (word == "xRedo") {
            if (!redoStack.empty()) {
                undoStack.push(redoStack.top());
                redoStack.pop();
                cout << "[Redo] Last undone word re-added.\n";
            } else {
            cout << "[Redo] Nothing to redo.\n";
            }
        } 
        //Normal word entered
        else {
            undoStack.push(word);
            
            //Clear redo stack
            while (!redoStack.empty()) {
                redoStack.pop();
            }
        }
    }
    
    stack<string> printStack;
    
    //Reverse stack order
    while (!undoStack.empty()) {
        printStack.push(undoStack.top());
        undoStack.pop();
    }
    //Put into queue
    while (!printStack.empty()) {
        finalStory.push(printStack.top());
        printStack.pop();
    }
    
    //Print final story
    cout << "Simple Text Editor\n";
    
    while (!finalStory.empty()) {
        cout << finalStory.front() << " ";
        finalStory.pop();
    }
    cout << endl;
    
    return 0;
}
