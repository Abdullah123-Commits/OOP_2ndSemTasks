#include <iostream>
using namespace std;

class Student {
private:
    const int roll_no; // Constant variable

public:
    // Constructor to initialize roll_no at runtime
    Student(int r) : roll_no(r) {}

    void display() const {
        cout << "Student Roll Number: " << roll_no << endl;
    }
};

int main() {
    int roll;
    cout << "Enter student roll number: ";
    cin >> roll;

    // Creating an object with runtime initialization
    Student s(roll);
    s.display();

    return 0;
}
