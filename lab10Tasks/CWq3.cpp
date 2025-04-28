#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

// User class
class User {
public:
    string user_id;
    string first_name;
    string last_name;
    string address;
    string email;

    User() {}
    User(string id, string fname, string lname, string addr, string mail) :
        user_id(id), first_name(fname), last_name(lname), address(addr), email(mail) {}

    static vector<User> loadUsers(const string& filename) {
        vector<User> users;
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string id, fname, lname, addr, mail;
            getline(ss, id, ',');
            getline(ss, fname, ',');
            getline(ss, lname, ',');
            getline(ss, addr, ',');
            getline(ss, mail, ',');
            users.push_back(User(id, fname, lname, addr, mail));
        }
        return users;
    }
};

// Product class
class Product {
public:
    string product_id;
    string product_name;
    string description;
    int price;

    Product() {}
    Product(string id, string name, string desc, int pr) :
        product_id(id), product_name(name), description(desc), price(pr) {}

    static vector<Product> loadProducts(const string& filename) {
        vector<Product> products;
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string id, name, desc, priceStr;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, desc, ',');
            getline(ss, priceStr, ',');
            products.push_back(Product(id, name, desc, stoi(priceStr)));
        }
        return products;
    }
};

// Order class
class Order {
public:
    string order_id;
    string user_id;
    string product_id;
    int total_paid;

    Order() {}
    Order(string oid, string uid, string pid, int paid) :
        order_id(oid), user_id(uid), product_id(pid), total_paid(paid) {}

    static vector<Order> loadOrders(const string& filename) {
        vector<Order> orders;
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string oid, uid, pid, paidStr;
            getline(ss, oid, ',');
            getline(ss, uid, ',');
            getline(ss, pid, ',');
            getline(ss, paidStr, ',');
            orders.push_back(Order(oid, uid, pid, stoi(paidStr)));
        }
        return orders;
    }
};

// Database class
class Database {
public:
    static void createDummyData() {
        ofstream users("users.txt");
        users << "u1,Linus,Torvalds,Finland,linus@email.com\n";
        users << "u2,Alan,Turing,UK,alan@email.com\n";
        users.close();

        ofstream products("products.txt");
        products << "p1,Laptop,High performance laptop,1000\n";
        products << "p2,Keyboard,Mechanical keyboard,100\n";
        products.close();

        ofstream orders("orders.txt");
        orders << "o1,u1,p1,1000\n"; // Linus ordered Laptop
        orders << "o2,u2,p2,100\n";  // Alan ordered Keyboard
        orders.close();
    }

    static void fetchProductsOfUser(const string& first_name) {
        vector<User> users = User::loadUsers("users.txt");
        vector<Product> products = Product::loadProducts("products.txt");
        vector<Order> orders = Order::loadOrders("orders.txt");

        string target_user_id = "";

        for (const auto& u : users) {
            if (u.first_name == first_name) {
                target_user_id = u.user_id;
                break;
            }
        }

        if (target_user_id == "") {
            cout << "User not found.\n";
            return;
        }

        cout << "Products ordered by " << first_name << ":\n";

        for (const auto& o : orders) {
            if (o.user_id == target_user_id) {
                for (const auto& p : products) {
                    if (p.product_id == o.product_id) {
                        cout << "- " << p.product_name << endl;
                    }
                }
            }
        }
    }
};

int main() {
    Database::createDummyData();           // Dummy data create karna
    Database::fetchProductsOfUser("Linus"); // Linus ke ordered products dikhana
    return 0;
}