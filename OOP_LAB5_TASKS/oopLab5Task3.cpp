#include <iostream>
#include <vector>

using namespace std;

class Book {
public:
    string title;
    string author;
    string isbn;

    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}
};

class Catalog {
private:
    vector<Book*> index;
public:
    void addBook(Book* book) {
        index.push_back(book);
    }

    void removeBook(string isbn) {
        for (auto i = index.begin(); i != index.end(); ++i) {
            if ((*i)->isbn == isbn) {
                index.erase(i);
                break;
            }
        }
    }

    void findBook(string isbn) {
        for (auto book : index) {
            if (book->isbn == isbn) {
                cout << book->title << '\n';
                return;
            }
        }
        cout << "Book not found" << '\n';
    }
};

class Library {
private:
    Catalog catalog;
    vector<Book*> books;
    string name;
    string address;

public:
    Library(string n, string addr) : name(n), address(addr) {}

    void addBook(Book* book) {
        books.push_back(book);
        catalog.addBook(book);
    }

    void removeBook(string isbn) {
        for (auto i = books.begin(); i != books.end(); ++i) {
            if ((*i)->isbn == isbn) {
                books.erase(i);
                catalog.removeBook(isbn);
                break;
            }
        }
    }

    void findBookInCatalog(string isbn) {
        catalog.findBook(isbn);
    }
};

int main() {
    Library myLibrary("Liaquat National Memorial Library", "Stadium Road");

    Book book1("Lord Of The Flies", "W.Golding", "12345");
    Book book2("The Prince And the Pauper", "Mark Twain", "67890");

    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);

    myLibrary.findBookInCatalog("12345");
    myLibrary.findBookInCatalog("67890");
    myLibrary.findBookInCatalog("11111");
    
    return 0;
}