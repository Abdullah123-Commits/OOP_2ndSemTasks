#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 500
#define MIN 0
using namespace std;

int main() {
    const int size = 20;
    float arr[size];
    // Seed the random number generator
    srand((time(0)));

    // Fill the array with random float values
    for (int i = 0; i < size; i++) {
        arr[i] = rand()% (MAX - MIN +1) + MIN;
    }
    float *ptr = arr;
    

    int sum=0;
    for(int i=0; i<size; i++){
        sum += *(ptr +i);
    }
    cout<<"SUM = "<<sum;

    
    return 0;
}
