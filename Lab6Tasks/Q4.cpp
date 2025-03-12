#include <iostream>
#include <string>
using namespace std;

class Books {
protected:
    string genre;

public:
    Books(string g) : genre(g) {}

    virtual void displayDetails() {
        cout << "Genre: " << genre << endl;
    }
};

class Novel : public Books {
private:
    string title;
    string author;

public:
    Novel(string t, string a) : Books("Novel"), title(t), author(a) {}

    void displayDetails() override {
        cout << "Genre: " << genre << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

class Mystery : public Books {
private:
    string title;
    string author;

public:
    Mystery(string t, string a) : Books("Mystery"), title(t), author(a) {}

    void displayDetails() override {
        cout << "Genre: " << genre << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

int main() {
    Novel novelBook("functional tranformer", "john ilyaz");
    Mystery mysteryBook("The Hound of the Baskervilles", "Arthur Conan Doyle");

    cout << "Library Books:\n" << endl;
    
    novelBook.displayDetails();
    cout << "\n";
    mysteryBook.displayDetails();

    return 0;
}
