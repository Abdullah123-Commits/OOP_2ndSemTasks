#include <iostream>
using namespace std;

// Abstract class Shape
class Shape {
public:
    // Pure virtual function
    virtual float getArea() = 0;
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    float length, width;

public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    float getArea() override {
        return length * width;
    }
};

// Derived class Triangle
class Triangle : public Shape {
private:
    float base, height;

public:
    Triangle(float b, float h) {
        base = b;
        height = h;
    }

    float getArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    // Creating objects
    Rectangle rect(10, 5);
    Triangle tri(8, 4);

    // Displaying areas
    cout << "Area of Rectangle: " << rect.getArea() << endl;
    cout << "Area of Triangle: " << tri.getArea() << endl;

    return 0;
}
