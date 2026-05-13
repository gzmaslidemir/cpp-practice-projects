#include <iostream>
using namespace std;

// Function prototypes
void merge(int arr[], int left, int mid, int right); //Merge puts two sorted parts together 
void sort(int arr[], int left, int right);           //Sort breaks array into smaller parts and sorts them

int main() 
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};  //starting numbers in the array
    int arr_size = sizeof(arr) / sizeof(arr[0]); //finds how many numbers are in the array
    
    //prints each number in the original array
    cout << "Given array is \n";
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
   
    sort(arr, 0, arr_size - 1); //calls merge sort function
    
    //prints each number in the sorted array
    cout << "\nSorted array is \n";
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1; //Find number of elements in the left array
    int n2 = right - mid;    //Find number of elements in the right array

    //Temporary arrays
    int* Left = new int[n1];
    int* Right = new int[n2];

    //copies left side numbers into Left array
    for (int i = 0; i < n1; i++) {
        Left[i] = arr[left + i];
    }
    //copies right side numbers into Right array
    for (int j = 0; j < n2; j++) {
        Right[j] = arr[mid + 1 + j];
    }
    
    //indexes
    int i = 0, j = 0;
    int k = left;
    
    //compares both sides and puts smaller number first
    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            arr[k++] = Left[i++];
        } else {
            arr[k++] = Right[j++];
        }
    }
    
    //copys remaining left side numbers
    //if there are any
    while (i < n1) {
        arr[k++] = Left[i++];
    }
    
    //copys remaining right side numbers
    //if there are any
    
    while (j < n2) {
        arr[k++] = Right[j++];
    }
    
    //deletes temp array
    delete[] Left;
    delete[] Right;
}

void sort(int arr[], int left, int right)
{
    
    if (left < right) { //checks if there is more than one number
        int mid = left + (right - left) / 2; //find the mid point

        sort(arr, left, mid); //sorts the left half
        sort(arr, mid + 1, right); //sorts the right half

        merge(arr, left, mid, right);  //merges the sorted halves
    }
}
