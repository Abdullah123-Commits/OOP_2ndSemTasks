#include <iostream>
#include <string>
using namespace std;

// Define the Book class
class Book {
private:
    string title;
    string author;
    float price;
    string publisher;
    int stock;

public:
    // Constructor to initialize the book details
    Book(string t, string a, float p, string pub, int s)
        : title(t), author(a), price(p), publisher(pub), stock(s) {}

    // Function to display book details
    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Stock: " << stock << endl;
    }

    // Function to check availability based on requested quantity
    bool checkAvailability(int requestedQuantity) {
        return requestedQuantity <= stock;
    }

    // Function to calculate total cost for the requested copies
    float calculateTotalCost(int requestedQuantity) {
        return price * requestedQuantity;
    }

    // Accessor functions to get title and author
    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }
};

// Function to search for a book by title and author using an array
Book* searchBook(Book books[], int size, string title, string author) {
    for (int i = 0; i < size; i++) {  // Loop through the array
        if (books[i].getTitle() == title && books[i].getAuthor() == author) {
            return &books[i];  // Return the address of the found book
        }
    }
    return nullptr;  // Return nullptr if not found
}

int main() {
    // Sample inventory with a list of books (use an array instead of a vector)
    Book booksInventory[3] = {
        Book("Python Basics", "John Doe", 29.99, "Tech Books", 50),
        Book("Advanced Python", "Jane Smith", 39.99, "Coding Press", 20),
        Book("Data Science Essentials", "Mark Lee", 49.99, "Data Press", 30)
    };

    string title, author;
    int requestedQuantity;

    // User input for book title and author
    cout << "Enter the title of the book: ";
    getline(cin, title);

    cout << "Enter the author of the book: ";
    getline(cin, author);

    // Search for the book in the array
    Book* book = searchBook(booksInventory, 3, title, author);

    // If book is found, display details and proceed
    if (book) {
        cout << "\nBook found! Here are the details:\n";
        book->displayBookDetails();

        // User input for the number of copies required
        cout << "\nEnter the number of copies required: ";
        cin >> requestedQuantity;

        // Check if the requested quantity is available
        if (book->checkAvailability(requestedQuantity)) {
            float totalCost = book->calculateTotalCost(requestedQuantity);
            cout << "\nTotal cost for " << requestedQuantity << " copies: $" << totalCost << endl;
        } else {
            cout << "Required copies not in stock." << endl;
        }
    } else {
        cout << "The requested book is not available in our inventory." << endl;
    }

    return 0;
}
