#include <iostream>
#include <string>
using namespace std;

// Base class Person
class Person {
protected:
    string name;
    int id;
    float salary;

public:
    virtual void getdata() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    virtual void displaydata() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }

    virtual void bonus() {
        cout << "Base class bonus: No bonus calculated.\n";
    }

    // Virtual destructor
    virtual ~Person() {}
};

// Admin class derived from Person
class Admin : virtual public Person {
public:
    void getdata() override {
        cout << "\n[Admin Data Input]\n";
        Person::getdata();
    }

    void displaydata() override {
        cout << "\n[Admin Data Display]\n";
        Person::displaydata();
    }

    void bonus() override {
        float admin_bonus = salary * 0.10;
        cout << "Admin Bonus: $" << admin_bonus << endl;
    }
};

// Account class derived from Person
class Account : virtual public Person {
public:
    void getdata() override {
        cout << "\n[Account Data Input]\n";
        Person::getdata();
    }

    void displaydata() override {
        cout << "\n[Account Data Display]\n";
        Person::displaydata();
    }

    void bonus() override {
        float account_bonus = salary * 0.15;
        cout << "Account Bonus: $" << account_bonus << endl;
    }
};

// Master class derived from Admin and Account
class Master : public Admin, public Account {
public:
    void getdata() override {
        cout << "\n[Master Data Input]\n";
        Person::getdata();  // Only one copy of Person due to virtual inheritance
    }

    void displaydata() override {
        cout << "\n[Master Data Display]\n";
        Person::displaydata();
    }

    void bonus() override {
        float master_bonus = salary * 0.20;
        cout << "Master Bonus: $" << master_bonus << endl;
    }
};

// Main function
int main() {
    Person* ptr;  // Base class pointer

    Admin adminObj;
    Account accountObj;
    Master masterObj;

    // Admin
    ptr = &adminObj;
    ptr->getdata();
    ptr->displaydata();
    ptr->bonus();

    // Account
    ptr = &accountObj;
    ptr->getdata();
    ptr->displaydata();
    ptr->bonus();

    // Master
    ptr = &masterObj;
    ptr->getdata();
    ptr->displaydata();
    ptr->bonus();

    return 0;
}
