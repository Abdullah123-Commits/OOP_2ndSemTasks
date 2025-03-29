#include <iostream>
using namespace std;

class Shape {
private:
    double length;
    double width;

public:
    // Constructor to initialize dimensions
    Shape(double l, double w) : length(l), width(w) {}

    // Function to calculate area
    double Area() const {
        return length * width;
    }

    // Overloading + operator to add the areas of two shapes
    double operator+(const Shape &other) const {
        return this->Area() + other.Area();
    }
};

int main() {
    // Create two objects of class Shape
    Shape shape1(10.0, 5.0); // Length = 10.0, Width = 5.0
    Shape shape2(7.0, 3.0);  // Length = 7.0, Width = 3.0

    // Calculate and display the total area by overloading +
    double totalArea = shape1 + shape2;
    cout << "The total area of shape1 and shape2 is: " << totalArea << endl;

    return 0;
}
