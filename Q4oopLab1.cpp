#include <iostream>
#include <cstdio>  // For printf
using namespace std;

int main () {
    float weight;
    cout << "Enter your weight in (kilograms): " << endl;
    cin >> weight;
    
    float ansWeight;
    ansWeight = 2.2 * weight;
    
    // Use printf to display the result with 2 decimal places
    printf("The weight in pounds after conversion is %.2f\n", ansWeight);

    return 0;
}
