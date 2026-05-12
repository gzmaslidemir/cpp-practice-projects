#include <iostream>
using namespace std;

//Function prototypes
int linearSearch(const int arr[], int size, int searchKey, int& iterations);
int binarySearch(const int arr[], int size, int searchKey, int& iterations);

int main() {

    const int SIZE = 100;
    // Predefined sorted array of 100 integers between 1 and 1000
    int arr[SIZE] = {
         1,  12,  25,  32,  43,  55,  61,  79,  84,  95,
       104, 113, 122, 131, 146, 157, 168, 175, 180, 191,
       201, 214, 221, 231, 241, 251, 266, 271, 281, 291,
       305, 313, 321, 335, 341, 351, 361, 371, 381, 391,
       404, 413, 421, 431, 441, 453, 461, 476, 484, 491,
       503, 516, 521, 531, 547, 551, 561, 571, 581, 591,
       607, 616, 621, 631, 641, 658, 661, 671, 681, 697,
       708, 711, 721, 731, 741, 751, 769, 771, 781, 791,
       808, 815, 821, 834, 841, 851, 861, 878, 881, 891,
       900, 919, 921, 931, 941, 955, 961, 976, 985, 998
    };
    
    
    //Variables for user input and results
    int searchKey;      //Value to search
    int choice;         //user choice
    int iterations = 0;  //counts number of steps
    int result;        //index results

    cout << "Enter the key value to serach for: ";
    cin >> searchKey;
    
    //Ask user which algorithm to use
    cout << "Choose the search algorithm: " << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    
    //Linear Search option
    if (choice == 1) {
        
        iterations = 0; //Reset counter
        result = linearSearch(arr, SIZE, searchKey, iterations);
        
        if (result != -1) {
       
            cout << "\nLinear Search: Key found at index " << result << " after " << iterations <<  " iterations." << endl;
            
        } else {
            
            cout << "\nLinear Search: Key not found after " << iterations << " iterations." << endl;
    }
}
    //Binary Serach option
    else if (choice == 2) {
        
        iterations = 0;
        result = binarySearch(arr, SIZE, searchKey, iterations);
        
        if (result != -1) {
       
            cout << "\nBinary Search: Key found at index " << result << " after " << iterations << " iterations." << endl;
            
        } else {
            
            cout << "\nBinary Search: Key not found after " << iterations << " iterations." << endl;
        }
    } else {
        cout << "Invalid choice" << endl;
     
     
    }
    return 0;
}
//Linear search function for sorted arrays
int linearSearch(const int arr[], int size, int searchKey, int& iterations) {
    
    for(int i = 0; i < size; i++) {
        
        iterations++;
        
        if (arr[i] == searchKey) {
            
            return i; //return index if found
            
        }
    }
     return -1;
}
//Binary search function dor unsorted arrays
int binarySearch(const int arr[], int size, int searchKey, int& iterations){
    
    int low = 0;
    int high = size - 1;
    int mid;
    
    while (low <= high) {
       
        iterations ++;
        mid = (low + high) / 2;
        
        if (arr[mid] == searchKey)//check middle eleman
        
        {
            return mid;
            
        }
        else if (arr[mid] < searchKey) //check right half
        {
            low =mid + 1;
        }
        else //check left half
        {
            high = mid - 1;
        }
    }
    
    return -1;
}
    
    
    


