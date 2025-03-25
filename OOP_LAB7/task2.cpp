#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

// BASE CLASS
class Shape {
protected:
    string color;
    string position;
    float borderThickness;

public:
    Shape(string c, string p, float b) : color(c), position(p), borderThickness(b) {}

    virtual void draw() {
        cout << "Drawing..." << endl;
    }

    virtual double calculateArea() {
        cout << "Calculating Area..." << endl;
        return 0.0;
    }

    virtual double calculatePerimeter() {
        cout << "Calculating Perimeter..." << endl;
        return 0.0;
    }
};

// DERIVED CLASS # 1 - Circle
class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r, string c, string p, float b) : Shape(c, p, b), radius(r) {}

    void draw() override {
        cout << "Drawing Circle..." << endl;
    }

    double calculateArea() override {
        return(M_PI * radius * radius);
    }

    double calculatePerimeter() override {
        return(2 * M_PI * radius);
    }

    float getRadius() { return radius; }
};

// DERIVED CLASS # 2 - Rectangle
class Rectangle : public Shape {
private:
    float width;
    float height;

public:
    Rectangle(float w, float h, string c, string p, float b) : Shape(c, p, b), width(w), height(h) {}

    void draw() override {
        cout << "Drawing Rectangle..." << endl;
    }

    double calculateArea() override {
        return(width * height);
    }

    double calculatePerimeter() override {
        return(2 * (width + height));
    }

    float getWidth() { return width; }
    float getHeight() { return height; }
};

// DERIVED CLASS # 3 - Triangle
class Triangle : public Shape {
private:
    float base;
    float height;

public:
    Triangle(float b, float h, string c, string p, float thickness) : Shape(c, p, thickness), base(b), height(h) {}

    void draw() override {
        cout << "Drawing Triangle..." << endl;
    }

    double calculateArea() override {
        return(0.5 * base * height);
    }

    double calculatePerimeter() override {
        // Perimeter calculation would need more info (e.g., sides of the triangle)
        cout << "Perimeter of Triangle: Not defined (need more info) , hence returning -1." << endl;
        return -1;
    }

    float getBase() { return base; }
    float getHeight() { return height; }
};

// DERIVED CLASS # 4 - Polygon
class Polygon : public Shape {
private:
    int numSides;
    float sideLength;

public:
    Polygon(int n, float s, string c, string p, float thickness) : Shape(c, p, thickness), numSides(n), sideLength(s) {}

    void draw() override {
        cout << "Drawing Polygon..." << endl;
    }

    double calculateArea() override {
        // Example: Area formula for a regular polygon (assuming number of sides > 2)
        if (numSides >= 3) {
            float area = (numSides * sideLength * sideLength) / (4 * tan(M_PI / numSides));
            return area;
        } else {
            cout << "Invalid Polygon , hence returning 1 as exit status..." << endl;
            return 1;
        }
    }

    double calculatePerimeter() override {
        return(numSides * sideLength);
    }

    int getNumSides() { return numSides; }
    float getSideLength() { return sideLength; }
};

int main() {
    // Create instances of each shape
    Circle circle(5.0, "Red", "Top-Left", 2.0);
    Rectangle rectangle(4.0, 6.0, "Blue", "Center", 1.5);
    Triangle triangle(4.0, 6.0, "Green", "Bottom-Right", 1.0);
    Polygon polygon(5, 3.0, "Yellow", "Top-Right", 0.5);

    // Test Circle
    cout << "Circle:" << endl;
    circle.draw();
    cout << "Area: " << circle.calculateArea() << endl;
    cout << "Perimeter: " << circle.calculatePerimeter() << endl;

    cout << endl;

    // Test Rectangle
    cout << "Rectangle:" << endl;
    rectangle.draw();
    cout << "Area: " << rectangle.calculateArea() << endl;
    cout << "Perimeter: " << rectangle.calculatePerimeter() << endl;

    cout << endl;

    // Test Triangle
    cout << "Triangle:" << endl;
    triangle.draw();
    cout << "Area: " << triangle.calculateArea() << endl;
    cout << "Perimeter: " << triangle.calculatePerimeter() << endl;

    cout << endl;

    // Test Polygon
    cout << "Polygon:" << endl;
    polygon.draw();
    cout << "Area: " << polygon.calculateArea() << endl;
    cout << "Perimeter: " << polygon.calculatePerimeter() << endl;

    return 0;
}