#include <iostream>
#include <vector>
#include <string>

// Define the inner structure to hold the subject
struct Subject {
    std::string subject;
};

// Define the outer structure for holding  ID and an array of subjects
struct Person {
    int id;
    Subject subjects[5];  // Fixed array of subjects (5 subjects max for each person)
};

int main() {
    int N;
    
    std::cout << "Enter the number of people: ";
    std::cin >> N;
    
    // Create a dynamic array (vector) of structures
    std::vector<Person> people(N);
    
    // Input data for each person
    for (int i = 0; i < N; i++) {  
        std::cout << "Enter ID for person " << i + 1 << ": ";
        std::cin >> people[i].id;

        // Ignore the newline character left in the buffer after reading the ID
        std::cin.ignore(); 

        std::cout << "Enter subjects for person " << i + 1 << " (maximum 5 subjects):\n";
        for (int j = 0; j < 5; j++) {  // Use post-increment here
            std::cout << "Subject " << j + 1 << ": ";
            std::getline(std::cin, people[i].subjects[j].subject);
        }
    }

    // Print the data for all people
    std::cout << "\nDisplaying all the information:\n";
    for (int i = 0; i < N; i++) {  
        std::cout << "ID: " << people[i].id << "\nSubjects: ";
        for (int j = 0; j < 5; j++) {  
            std::cout << people[i].subjects[j].subject << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
