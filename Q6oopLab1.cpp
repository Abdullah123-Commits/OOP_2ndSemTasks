#include <iostream>
#include <cstdio>
#include <string>
#define SIZE 5
using namespace std;

int main() {
    string firstName,lastName,fullName;
    cout << "Enter first name of student:"<<endl;
    cin >> firstName;
    cout << "Enter last name of student:"<<endl;
    cin >> lastName;
    string space = " ";
    fullName = firstName + space + lastName;
    float testScores[SIZE];
    for (int i=0; i<SIZE; i++) {
        cout << "Enter "<<i+1<<" test marks for student"<<endl;
        cin >> testScores[i];
    }
    float sum=0;
    cout << "\nStudent Name: "<<fullName;
    printf("\n");
    for (int i=0; i<SIZE; i++) {
        sum+=testScores[i];
        printf(" %.2f ",testScores[i]);
    }
    float avgTestScore = sum/SIZE;
    printf("\nAverage Test Score : %.2f", avgTestScore);
    return 0;
}