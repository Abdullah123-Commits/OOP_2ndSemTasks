#include <iostream>
#include <string> 

struct Person {
    int id;
    std::string name; 
};

// Function to print the array of structures
void printArray(Person people[], int N) {
    for (int i = 0; i < N; i++) {
        std::cout << "ID: " << people[i].id << ", Name: " << people[i].name << std::endl;
    }
}

// Comparator function to sort first by ID
bool compareById(const Person& a, const Person& b) {
    return a.id < b.id;  
}

// Comparator function to sort by the first character of the name
bool compareByName(const Person& a, const Person& b) {
    return a.name[0] < b.name[0];  
}

void sortPeopleById(Person people[], int N) {
    // Bubble sort implementation for sorting by id
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (!compareById(people[j], people[j + 1])) {
                Person temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
}

void sortPeopleByName(Person people[], int N) {
    // Bubble sort implementation for sorting by the first character of the name
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (!compareByName(people[j], people[j + 1])) {
                Person temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N;
    std::cout << "Enter the number of people: ";
    std::cin >> N;

    Person people[N];

    for (int i = 0; i < N; i++) {
        std::cout << "Enter ID for person " << i + 1 << ": ";
        std::cin >> people[i].id;
        std::cout << "Enter Name for person " << i + 1 << ": ";
        std::cin.ignore(); // To ignore the newline left by std::cin
        std::getline(std::cin, people[i].name); 
    }

    // Sort the people array first by ID
    sortPeopleById(people, N);
    std::cout << "\nSorted by ID:\n";
    printArray(people, N);

    // Sort the people array now by the first character of Name
    sortPeopleByName(people, N);
    std::cout << "\nSorted by the first character of Name:\n";
    printArray(people, N);

    return 0;
}
