#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base Media class
class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
    bool isCheckedOut;

public:
    Media(string t, string pubDate, string id, string pub)
        : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub), isCheckedOut(false) {}

    virtual void displayInfo() {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate
            << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher
            << "\nChecked Out: " << (isCheckedOut ? "Yes" : "No") << endl;
    }

    virtual void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << title << " has been checked out." << endl;
        } else {
            cout << title << " is already checked out." << endl;
        }
    }

    virtual void returnItem() {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << title << " has been returned." << endl;
        } else {
            cout << title << " is not currently checked out." << endl;
        }
    }

    string getTitle() { return title; }

    virtual ~Media() {}
};

// Derived classes: Book, DVD, CD, Magazine
class Book : public Media {
private:
    string author, ISBN;
    int numberOfPages;

public:
    Book(string t, string pubDate, string id, string pub, string a, string isbn, int pages)
        : Media(t, pubDate, id, pub), author(a), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
private:
    string director, rating;
    int duration;

public:
    DVD(string t, string pubDate, string id, string pub, string dir, string r, int dur)
        : Media(t, pubDate, id, pub), director(dir), rating(r), duration(dur) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration
            << " minutes\nRating: " << rating << endl;
    }
};

class CD : public Media {
private:
    string artist, genre;
    int numberOfTracks;

public:
    CD(string t, string pubDate, string id, string pub, string art, string gen, int tracks)
        : Media(t, pubDate, id, pub), artist(art), genre(gen), numberOfTracks(tracks) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nGenre: " << genre
            << "\nTracks: " << numberOfTracks << endl;
    }
};

class Magazine : public Media {
private:
    string editor;
    int issueNumber;

public:
    Magazine(string t, string pubDate, string id, string pub, string ed, int issue)
        : Media(t, pubDate, id, pub), editor(ed), issueNumber(issue) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Editor: " << editor << "\nIssue Number: " << issueNumber << endl;
    }
};

// Library class for managing media
class Library {
    private:
        vector<Media *> collection;
    
    public:
        void addMedia(Media *item) {
            collection.push_back(item);
        }
    
        void searchMedia(string title) {
            for (int i = 0; i < collection.size(); i++) { // Conventional for loop
                if (collection[i]->getTitle() == title) {
                    cout << "Media found:\n";
                    collection[i]->displayInfo();
                    return;
                }
            }
            cout << "Media titled \"" << title << "\" not found in the library." << endl;
        }
    
        void displayAllMedia() {
            for (int i = 0; i < collection.size(); i++) { // Conventional for loop
                collection[i]->displayInfo();
                cout << "----------------------\n";
            }
        }
    
        // Method to access a specific media item
        Media* getMediaByIndex(int index) {
            if (index >= 0 && index < collection.size()) {
                return collection[index];
            }
            return nullptr; // Return nullptr if the index is invalid
        }
    
        ~Library() {
            for (int i = 0; i < collection.size(); i++) { // Conventional for loop
                delete collection[i];
            }
        }
    };
    

// Main function
int main() {
    Library library;

    // Adding media to the library
    library.addMedia(new Book("C++ Fundamentals", "2023", "B001", "TechPress", "John Doe", "123-456-789", 450));
    library.addMedia(new DVD("The Matrix", "1999", "D001", "Warner Bros.", "Wachowskis", "R", 136));
    library.addMedia(new CD("Greatest Hits", "2020", "C001", "MusicPro", "The Band", "Rock", 15));
    library.addMedia(new Magazine("Tech Today", "2024", "M001", "MediaGroup", "Jane Smith", 42));

    // Search, checkout, and return functionalities
    cout << "Displaying all media:\n";
    library.displayAllMedia();

    cout << "Searching for \"The Matrix\":\n";
    library.searchMedia("The Matrix");

    cout << "\nChecking out \"The Matrix\":\n";
    Media *matrixDVD = library.getMediaByIndex(1); // Using public getter method
    if (matrixDVD != nullptr) {
        matrixDVD->checkOut();
    }

    cout << "\nReturning \"The Matrix\":\n";
    if (matrixDVD != nullptr) {
        matrixDVD->returnItem();
    }

    return 0;
}

