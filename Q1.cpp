#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 500
#define MIN 0

using namespace std;

int main() {
    const int size = 20;
    float arr[size];
    float *ptr = arr;

    // Seed the random number generator
    srand((time(0)));

    // Fill the array with random float values
    for (int i = 0; i < size; i++) {
        arr[i] = rand()% (MAX - MIN +1) + MIN;
    }

    // Initialize highest and second_highest
    float highest = *ptr;
    float second_highest = *ptr;

    // Traverse the array using pointer
    for (int i = 1; i < size; i++) {
        if (*(ptr + i) > highest) {
            second_highest = highest;
            highest = *(ptr + i);
        } else if (*(ptr + i) > second_highest && *(ptr + i) < highest) {
            second_highest = *(ptr + i);
        }
    }

    // Output the results
    cout << "The highest number is: " << highest << endl;
    cout << "The second highest number is: " << second_highest << endl;

    return 0;
}
