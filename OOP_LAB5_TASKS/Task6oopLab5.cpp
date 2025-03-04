#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct MenuItem {
    string name;
    string type; // "drink" or "food"
    double price;
};

class CoffeeShop {
public:
    const string Name;
    MenuItem* Menu;
    int menuSize;
    string* orders;
    int orderCount;
    int orderCapacity;

    CoffeeShop(const string& name, int capacity, MenuItem* menu, int size) : 
        Name(name), 
        Menu(menu), 
        menuSize(size), 
        orderCapacity(capacity), 
        orderCount(0) 
    {
        orders = new string[orderCapacity];
    }

    ~CoffeeShop() {
        delete[] orders;
    }

    void addOrder(const string& itemName) {
        for (int i = 0; i < menuSize; ++i) {
            if (Menu[i].name == itemName) {
                if (orderCount < orderCapacity) {
                    orders[orderCount++] = itemName;
                    cout << "Order added: " << itemName << endl;
                } else {
                    cout << "Order capacity reached!" << endl;
                }
                return;
            }
        }
        cout << "This item is currently unavailable!" << endl;
    }

    void fulfillOrder() {
        if (orderCount > 0) {
            cout << "The " << orders[0] << " is ready!" << endl;
            // Shift orders to the left
            for (int i = 1; i < orderCount; ++i) {
                orders[i - 1] = orders[i];
            }
            --orderCount;
        } else {
            cout << "All orders have been fulfilled!" << endl;
        }
    }

    void listOrders() const {
        if (orderCount > 0) {
            cout << "Current orders:" << endl;
            for (int i = 0; i < orderCount; ++i) {
                cout << orders[i] << endl;
            }
        } else {
            cout << "No orders." << endl;
        }
    }

    double dueAmount() const {
        double total = 0;
        for (int i = 0; i < orderCount; ++i) {
            for (int j = 0; j < menuSize; ++j) {
                if (orders[i] == Menu[j].name) {
                    total += Menu[j].price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() const {
        if (menuSize == 0) return "";
        int minIndex = 0;
        for (int i = 1; i < menuSize; ++i) {
            if (Menu[i].price < Menu[minIndex].price) {
                minIndex = i;
            }
        }
        return Menu[minIndex].name;
    }

    void drinksOnly() const {
        cout << "Drinks available:" << endl;
        for (int i = 0; i < menuSize; ++i) {
            if (Menu[i].type == "drink") {
                cout << Menu[i].name << endl;
            }
        }
    }

    void foodOnly() const {
        cout << "Food available:" << endl;
        for (int i = 0; i < menuSize; ++i) {
            if (Menu[i].type == "food") {
                cout << Menu[i].name << endl;
            }
        }
    }
};

int main() {
    MenuItem menu[] = {
        {"Coffee", "drink", 3.0},
        {"Tea", "drink", 2.5},
        {"Sandwich", "food", 5.0},
        {"Cake", "food", 4.5}
    };
    int menuSize = sizeof(menu) / sizeof(menu[0]);

    CoffeeShop shop("JavaBeans", 10, menu, menuSize);

    shop.addOrder("Coffee");
    shop.addOrder("Sandwich");
    shop.addOrder("Burger"); // Unavailable item

    shop.listOrders();

    cout << "Total amount due: $" << shop.dueAmount() << endl;

    shop.fulfillOrder();
    shop.fulfillOrder();
    shop.fulfillOrder(); // No more orders

    shop.drinksOnly();
    shop.foodOnly();

    cout << "Cheapest item: " << shop.cheapestItem() << endl;

    return 0;
}
