/*Task - 01:
Your task is to create a Circle constructor that creates a circle with a radius provided by an argument. The
circles constructed must have two getters getArea() (PIr^2) and getPerimeter() (2PI*r) which give both
respective areas and perimeter (circumference).
*/
#include <iostream>
using namespace std;

class Circle {
    private:
        float radius;
        const double PI = 3.141592;
    public:
        Circle(float radius) {
            this->radius = radius;
        }
        // area getter
        double getArea() {
            return(PI*radius*radius);
        }
        //PERIMETER
        double getPerimeter() {
            return(PI*radius*2);
        }

};

int main () {
    // Create a Circle object with radius 5.0
    Circle c(5.0);
    
    // Output the area and perimeter of the circle
    cout << "Area: " << c.getArea() << endl;
    cout << "Perimeter: " << c.getPerimeter() << endl;
    return 0;
}