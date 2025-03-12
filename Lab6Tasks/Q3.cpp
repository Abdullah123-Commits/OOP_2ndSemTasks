#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee
{
protected:
    int id;
    string name;

public:
    Employee(int id, string name) : id(id), name(name) {}
    virtual void displayInfo() const
    {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
    virtual ~Employee() {}
};

// Interfaces
class IOrderTaker
{
public:
    virtual void takeOrder(const string &order) = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer
{
public:
    virtual void prepareOrder(const string &order) = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller
{
public:
    virtual void generateBill(const vector<string> &items) = 0;
    virtual ~IBiller() {}
};

class Menu
{
protected:
    vector<pair<string, double>> items;

public:
    void addItem(const string &name, double price)
    {
        items.push_back({name, price});
    }

    virtual double calculateTotal() const = 0;

    virtual void displayMenu() const
    {
        for (const auto &item : items)
        {
            cout << item.first << " - $" << item.second << endl;
        }
    }

    virtual ~Menu() {}
};

class FoodMenu : public Menu
{
public:
    double calculateTotal() const override
    {
        double total = 0;
        for (const auto &item : items)
            total += item.second;
        return total;
    }
};

class BeverageMenu : public Menu
{
public:
    double calculateTotal() const override
    {
        double total = 0;
        for (const auto &item : items)
            total += item.second * 1.1; // 10% tax for drinks
        return total;
    }
};

class Waiter : public Employee, public IOrderTaker
{
public:
    Waiter(int id, const string &name) : Employee(id, name) {}
    void takeOrder(const string &order) override
    {
        cout << name << " took order: " << order << endl;
    }
};

class Chef : public Employee, public IOrderPreparer
{
public:
    Chef(int id, const string &name) : Employee(id, name) {}
    void prepareOrder(const string &order) override
    {
        cout << name << " is making: " << order << endl;
    }
};

class Cashier : public Employee, public IBiller
{
public:
    Cashier(int id, const string &name) : Employee(id, name) {}
    void generateBill(const vector<string> &items) override
    {
        cout << name << " made bill for: " << endl;
        for (const auto &item : items)
            cout << " - " << item << endl;
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller
{
public:
    Manager(int id, const string &name) : Employee(id, name) {}

    void takeOrder(const string &order) override
    {
        cout << name << " took order: " << order << endl;
    }

    void generateBill(const vector<string> &items) override
    {
        cout << name << " made bill for: " << endl;
        for (const auto &item : items)
            cout << " - " << item << endl;
    }
};

int main()
{
    FoodMenu foodMenu;
    foodMenu.addItem("Burger", 5.0);
    foodMenu.addItem("Fries", 3.0);

    BeverageMenu bevMenu;
    bevMenu.addItem("Cola", 2.0);
    bevMenu.addItem("Coffee", 3.5);

    // Employees
    Waiter waiter(1, "Alice");
    Chef chef(2, "Bob");
    Cashier cashier(3, "Charlie");
    Manager manager(4, "Diana");

    // Simulate order process
    waiter.takeOrder("Burger and Cola");
    chef.prepareOrder("Burger and Cola");

    vector<string> items = {"Burger", "Cola"};
    cashier.generateBill(items);

    // Manager acting in dual roles
    manager.takeOrder("Fries and Coffee");
    manager.generateBill({"Fries", "Coffee"});

    // Menu totals
    cout << "Total food cost: $" << foodMenu.calculateTotal() << endl;
    cout << "Total drink cost (with tax): $" << bevMenu.calculateTotal() << endl;

    return 0;
}
