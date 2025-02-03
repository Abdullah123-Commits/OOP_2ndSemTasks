/*Write a program that calculates the sum of all the elements in array using pointers
(Note: Generate the array via user in the main function use argv)*/
#include <iostream>
#include <cstdlib>  // For atoi
using namespace std;

int main(int argc, char* argv[]) {
    int sum = 0;

    // Start from argv[1] because argv[0] is the program name
    for (int i = 1; i < argc; i++) {
        // Pointer to the current argument string
        char* ptr = argv[i];  

        // Convert string to integer using atoi and add to sum
        sum += atoi(ptr);    
    }
    cout << "The arguments passed are:" << argc << endl;
    cout << "argv[0]" << argv[0] << endl;

    cout << "The sum of numbers passed in the array argv is " << sum << endl;
    return 0;
}


