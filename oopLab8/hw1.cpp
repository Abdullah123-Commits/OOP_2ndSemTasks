#include <iostream>
using namespace std;

class Number {
private:
    int value; // Store the number
public:
    // Constructor to initialize the number
    Number(int val) : value(val) {}

    // Overload prefix decrement operator (--x)
    Number& operator--() {
        value *= 4; // Multiply the number by 4
        return *this; // Return the current object
    }

    // Overload postfix decrement operator (x--)
    Number operator--(int) {
        Number temp = *this; // Store the current state
        value /= 4;          // Divide the number by 4
        return temp;         // Return the stored state
    }

    // Function to display the value
    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number num(8); // Initialize the number with 8

    cout << "Initial ";
    num.display();

    // Using prefix decrement operator (--num)
    --num;
    cout << "After prefix decrement (--): ";
    num.display();

    // Using postfix decrement operator (num--)
    num--;
    cout << "After postfix decrement (--): ";
    num.display();

    return 0;
}
