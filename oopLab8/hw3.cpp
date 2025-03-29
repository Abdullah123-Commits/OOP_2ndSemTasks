#include <iostream>
#include <string>
using namespace std;

// Base class: Person
class Person {
protected:
    int employeeID; // Data member to store Employee ID

public:
    // Member function to get data for Person
    virtual void getData() {
        cout << "Enter Employee ID: ";
        cin >> employeeID;
    }

    // Member function to display data for Person
    virtual void displayData() const {
        cout << "Employee ID: " << employeeID << endl;
    }

    virtual ~Person() {} // Virtual destructor
};

// Derived class: Admin
class Admin : public Person {
private:
    string name;          // Name of the employee
    double monthlyIncome; // Monthly income

public:
    // Member function to get data for Admin
    void getData() override {
        Person::getData(); // Get Employee ID
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    // Member function to calculate bonus for Admin
    double bonus() const {
        return monthlyIncome * 0.05; // 5% annual bonus
    }

    // Member function to display data for Admin
    void displayData() const override {
        Person::displayData(); // Display Employee ID
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Annual Bonus: " << bonus() << endl;
    }
};

// Derived class: Accounts
class Accounts : public Person {
private:
    string name;          // Name of the employee
    double monthlyIncome; // Monthly income

public:
    // Member function to get data for Accounts
    void getData() override {
        Person::getData(); // Get Employee ID
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    // Member function to calculate bonus for Accounts
    double bonus() const {
        return monthlyIncome * 0.05; // 5% annual bonus
    }

    // Member function to display data for Accounts
    void displayData() const override {
        Person::displayData(); // Display Employee ID
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Annual Bonus: " << bonus() << endl;
    }
};

int main() {
    // Create objects for Admin and Accounts
    Admin adminEmployee;
    Accounts accountsEmployee;

    cout << "Enter details for Admin Employee:\n";
    adminEmployee.getData();

    cout << "\nEnter details for Accounts Employee:\n";
    accountsEmployee.getData();

    // Display details and bonuses
    cout << "\nAdmin Employee Details:\n";
    adminEmployee.displayData();

    cout << "\nAccounts Employee Details:\n";
    accountsEmployee.displayData();

    return 0;
}
