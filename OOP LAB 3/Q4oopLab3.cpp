#include <iostream>
using namespace std;

class Employee {
private:
    double monthlySalary;

public:
    string firstName;
    string lastName;

    // Constructor with validation for positive salary
    Employee(string firstName = "", string lastName = "", double monthlySalary = 0.0) {
        this->firstName = firstName;
        this->lastName = lastName;
        // If salary is not positive, set it to 0.0
        this->monthlySalary = (monthlySalary > 0.0) ? monthlySalary : 0.0;
    }

    // Getter for monthly salary
    double getMonthlySalary() const {
        return monthlySalary;
    }

    // Setter to validate and set salary
    void setMonthlySalary(double monthlySalary) {
        if (monthlySalary > 0.0) {
            this->monthlySalary = monthlySalary;
        } else {
            this->monthlySalary = 0.0;
        }
    }

    // Method to calculate yearly salary
    double yearlySalary() const {
        return 12 * monthlySalary;
    }

    // Method to give a 10% raise
    void incrementSalary(double incrementPercentage) {
        monthlySalary += (incrementPercentage / 100) * monthlySalary;
    }
};

int main() {
    // Create two Employee objects with different initial salaries
    Employee testObj1("John", "Doe", 5000); // Name + Salary
    Employee testObj2("Jane", "Smith", 10000);

    // Display yearly salary of both employees before raise
    cout << testObj1.firstName << " " << testObj1.lastName << "'s yearly salary is: " << testObj1.yearlySalary() << endl;
    cout << testObj2.firstName << " " << testObj2.lastName << "'s yearly salary is: " << testObj2.yearlySalary() << endl;

    // Apply a 10% raise
    testObj1.incrementSalary(10.0);
    testObj2.incrementSalary(10.0);

    // Display yearly salary of both employees after raise
    cout << testObj1.firstName << " " << testObj1.lastName << "'s yearly salary after raise is: " << testObj1.yearlySalary() << endl;
    cout << testObj2.firstName << " " << testObj2.lastName << "'s yearly salary after raise is: " << testObj2.yearlySalary() << endl;

    return 0;
}
