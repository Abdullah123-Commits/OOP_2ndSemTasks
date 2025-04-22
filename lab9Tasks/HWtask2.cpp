#include <iostream>
#include <string>
using namespace std;

// Abstract class Car
class Car {
protected:
    string model;
    float price;

public:
    void setModel(string m) {
        model = m;
    }

    string getModel() {
        return model;
    }

    float getPrice() {
        return price;
    }

    // Abstract method
    virtual void setPrice(float p) = 0;
};

// Subclass Color
class Color : public Car {
private:
    string color;

public:
    void setColor(string c) {
        color = c;
    }

    string getColor() {
        return color;
    }

    // Implement setPrice
    void setPrice(float p) override {
        price = p + 1000;  // Additional cost for color
    }

    void displayInfo() {
        cout << "Car Model: " << model << endl;
        cout << "Color: " << color << endl;
        cout << "Price: $" << price << endl;
    }
};

// Subclass Company
class Company : public Car {
private:
    string company;

public:
    void setCompany(string c) {
        company = c;
    }

    string getCompany() {
        return company;
    }

    // Implement setPrice
    void setPrice(float p) override {
        price = p + 2000;  // Additional cost for brand
    }

    void displayInfo() {
        cout << "Car Model: " << model << endl;
        cout << "Company: " << company << endl;
        cout << "Price: $" << price << endl;
    }
};

// Main function
int main() {
    Color coloredCar;
    coloredCar.setModel("Sedan");
    coloredCar.setColor("Red");
    coloredCar.setPrice(15000);  // base price + color cost
    coloredCar.displayInfo();

    cout << endl;

    Company companyCar;
    companyCar.setModel("SUV");
    companyCar.setCompany("Toyota");
    companyCar.setPrice(20000);  // base price + brand cost
    companyCar.displayInfo();

    return 0;
}
