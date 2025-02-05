/*
    Write a program that can resize a single dimension int array if the elements exceed the total size.
    Consider an int array of size 5 (uninitialized), you start adding items to the array and if the quantity of
    the elements exceeds double the array size. Once finished resizing the array again to the max quantity of
    the elements present in the array.
*/

#include <iostream>
#define SIZE 5
using namespace std;

int main() {
    int* arr = new int[SIZE];  // Dynamically allocate the array
    int present = 0;
    char choice;
    int isDone = 0;     //BY DEFAULT SET TO 0 REPRESENTING THAT ELEMENT INSERTION NOT COMPLETED
    int currentSize = SIZE;

    while (isDone == 0) {
        if (present < currentSize) {
            cout << "Enter the element at index " << present << ": ";
            cin >> arr[present];
            present++;

            cout << "Press 'D' or 'd' if you are done with element insertion, else press any key to continue: ";
            cin >> choice;

            if (choice == 'D' || choice == 'd') {
                isDone = 1;
            }
        } else {
            // Resize the array if more space is needed
            int newSize = 2 * currentSize;
            int* newArr = new int[newSize];  // Create a new array with double the size

            // Copy elements from old array to new array
            for (int i = 0; i < currentSize; i++) {
                newArr[i] = arr[i];
            }

            delete[] arr;  // Delete the old array to free memory
            arr = newArr;  // Point arr to the new array
            currentSize = newSize;  // Update the current size
        }
    }

    // Now that we’re done, print the final array content
    cout << "Final array elements: ";
    for (int i = 0; i < present; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;  // Free the allocated memory
    return 0;
}
