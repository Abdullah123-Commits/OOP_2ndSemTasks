#include <iostream>
#include <string>
using namespace std;

class Vehicles
{
protected:
    float price;

public:
    void setPrice(float p)
    {
        price = p;
    }

    float getPrice() const
    {
        return price;
    }
};

class Car : public Vehicles
{
protected:
    int seatingCapacity;
    int numberOfDoors;
    string fuelType;

public:
    void setCarDetails(int capacity, int doors, string fuel)
    {
        seatingCapacity = capacity;
        numberOfDoors = doors;
        fuelType = fuel;
    }

    void displayCarDetails() const
    {
        cout << "Price: $" << price << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Number of Doors: " << numberOfDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Motorcycle : public Vehicles
{
protected:
    int numberOfCylinders;
    int numberOfGears;
    int numberOfWheels;

public:
    void setMotorcycleDetails(int cylinders, int gears, int wheels)
    {
        numberOfCylinders = cylinders;
        numberOfGears = gears;
        numberOfWheels = wheels;
    }

    void displayMotorcycleDetails() const
    {
        cout << "Price: $" << price << endl;
        cout << "Number of Cylinders: " << numberOfCylinders << endl;
        cout << "Number of Gears: " << numberOfGears << endl;
        cout << "Number of Wheels: " << numberOfWheels << endl;
    }
};

class Audi : public Car
{
private:
    string modelType;

public:
    void setModelType(string model)
    {
        modelType = model;
    }

    void displayAudiDetails() const
    {
        displayCarDetails();
        cout << "Model Type: " << modelType << endl;
    }
};

class Yamaha : public Motorcycle
{
private:
    string makeType;

public:
    void setMakeType(string make)
    {
        makeType = make;
    }

    void displayYamahaDetails() const
    {
        displayMotorcycleDetails();
        cout << "Make Type: " << makeType << endl;
    }
};

int main()
{

    Audi myAudi;
    myAudi.setPrice(50000);
    myAudi.setCarDetails(5, 4, "Petrol");
    myAudi.setModelType("A6");

    cout << "Audi Car Details:\n";
    myAudi.displayAudiDetails();

    cout << "\n";

    Yamaha myYamaha;
    myYamaha.setPrice(15000);
    myYamaha.setMotorcycleDetails(2, 6, 2);
    myYamaha.setMakeType("R1");

    cout << "Yamaha Motorcycle Details:\n";
    myYamaha.displayYamahaDetails();

    return 0;
}
