#include <iostream>
#include <string>
using namespace std;

// MenuItem class to hold details about each menu item
class MenuItem {
public:
    string itemName;
    string itemType; // "food" or "drink"
    float price;

    // Constructor to initialize menu item details
    MenuItem(string name, string type, float pr) : itemName(name), itemType(type), price(pr) {}
    
    // Default constructor
    MenuItem() : itemName(""), itemType(""), price(0.0f) {}
};

// CoffeeShop class containing the shop's details and functionality
class CoffeeShop {
private:
    string name;
    MenuItem menu[5];  // Maximum 5 items in the menu (array size is fixed)
    string orders[10]; // Maximum 10 orders in the order list (array size is fixed)
    int orderCount;    // To track the number of orders added

public:
    // Constructor to initialize CoffeeShop with its name and menu items
    CoffeeShop(string shopName, MenuItem menuItems[], int menuSize) {
        name = shopName;
        for (int i = 0; i < menuSize; i++) {
            menu[i] = menuItems[i];  // Proper initialization of menu array
        }
        orderCount = 0; // Initialize orders array as empty
    }

    // Method to add an order if the item is on the menu
    string addOrder(string itemName) {
        bool itemFound = false;
        for (int i = 0; i < 5; i++) {
            if (menu[i].itemName == itemName) {
                if (orderCount < 10) { // Check if there is space for more orders
                    orders[orderCount++] = itemName;
                    itemFound = true;
                    return "Order for " + itemName + " added.";
                }
                return "Cannot add more orders, the order list is full.";
            }
        }
        if (!itemFound) {
            return "This item is currently unavailable";
        }
        return "";
    }

    // Method to fulfill an order
    string fulfillOrder() {
        if (orderCount > 0) {
            string item = orders[0];
            // Shift all items in the order array to the left
            for (int i = 1; i < orderCount; i++) {
                orders[i - 1] = orders[i];
            }
            orderCount--; // Decrease order count after fulfilling
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    // Method to list all orders
    string listOrders() {
        if (orderCount == 0) {
            return "[]"; // Return empty array if no orders
        }
        string orderList = "[";
        for (int i = 0; i < orderCount; i++) {
            orderList += orders[i];
            if (i != orderCount - 1) orderList += ", ";
        }
        orderList += "]";
        return orderList;
    }

    // Method to calculate the total amount due for all orders
    float dueAmount() {
        float total = 0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < 5; j++) {
                if (menu[j].itemName == orders[i]) {
                    total += menu[j].price;
                    break;
                }
            }
        }
        return total;
    }

    // Method to find the cheapest item on the menu
    string cheapestItem() {
        float minPrice = menu[0].price;
        string cheapest = menu[0].itemName;
        for (int i = 1; i < 5; i++) {
            if (menu[i].price < minPrice) {
                minPrice = menu[i].price;
                cheapest = menu[i].itemName;
            }
        }
        return cheapest;
    }

    // Method to return only drink items from the menu
    string drinksOnly() {
        string drinks = "";
        for (int i = 0; i < 5; i++) {
            if (menu[i].itemType == "drink") {
                if (drinks != "") drinks += ", ";
                drinks += menu[i].itemName;
            }
        }
        return drinks;
    }

    // Method to return only food items from the menu
    string foodOnly() {
        string food = "";
        for (int i = 0; i < 5; i++) {
            if (menu[i].itemType == "food") {
                if (food != "") food += ", ";
                food += menu[i].itemName;
            }
        }
        return food;
    }
};

int main() {
    // Create a few menu items for the CoffeeShop
    MenuItem menuItems[5] = {
        MenuItem("Cappuccino", "drink", 4.50),
        MenuItem("Latte", "drink", 5.00),
        MenuItem("Muffin", "food", 2.50),
        MenuItem("Croissant", "food", 3.00),
        MenuItem("Espresso", "drink", 3.00)
    };

    // Create a CoffeeShop instance
    CoffeeShop shop("Java Haven", menuItems, 5);

    // Test methods of the CoffeeShop class
    cout << shop.addOrder("Cappuccino") << endl;
    cout << shop.addOrder("Muffin") << endl;
    cout << shop.addOrder("Pasta") << endl;

    cout << shop.fulfillOrder() << endl;

    cout << "Orders: " << shop.listOrders() << endl;

    cout << "Total Amount Due: $" << shop.dueAmount() << endl;

    cout << "Cheapest Item: " << shop.cheapestItem() << endl;

    cout << "Drinks Only: " << shop.drinksOnly() << endl;
    cout << "Food Only: " << shop.foodOnly() << endl;

    return 0;
}
