#include <iostream>
#include <fstream>
#include <string>
#include <vector> // For storing filtered employees
using namespace std;

class Employee {
public:
    int id;
    string name;
    string designation;
    int years_of_service;

    Employee(int i, string n, string d, int y)
        : id(i), name(n), designation(d), years_of_service(y) {}

    void writeToFile(ofstream &outFile) const {
        outFile << id << "," << name << "," << designation << "," << years_of_service << endl;
    }

    void display() const {
        cout << id << ", " << name << ", " << designation << ", " << years_of_service << endl;
    }

    static bool isManagerWithAtLeastTwoYears(const Employee& emp) {
        return emp.designation == "Manager" && emp.years_of_service >= 2;
    }
};

int main() {
    // Create 4 employee objects with dummy data
    Employee emp1(1, "John Doe", "Manager", 5);
    Employee emp2(2, "Jane Smith", "Engineer", 3);
    Employee emp3(3, "Emily Davis", "Designer", 2);
    Employee emp4(4, "Michael Brown", "Manager", 1);

    // Write dummy data to file
    ofstream outFile("employees.txt");
    if (outFile.is_open()) {
        outFile << "ID,Name,Designation,Years_of_Service\n"; // Header
        emp1.writeToFile(outFile);
        emp2.writeToFile(outFile);
        emp3.writeToFile(outFile);
        emp4.writeToFile(outFile);
        outFile.close();
        cout << "Data written to file successfully!\n";
    } else {
        cout << "Error opening file for writing!\n";
    }

    // ======================= PART A: READ AND FILTER ============================
    ifstream inFile("employees.txt");
    vector<Employee> filteredEmployees; // To store matching employees

    if (inFile.is_open()) {
        string header;
        getline(inFile, header);  // Skip header

        cout << "\nSearching for Manager with at least 2 years of service...\n";

        while (!inFile.eof()) {
            int id, years_of_service;
            string name, designation;
            char comma;

            inFile >> id >> comma;
            getline(inFile, name, ',');
            getline(inFile, designation, ',');
            inFile >> years_of_service;
            inFile.ignore(); // Ignore newline after years

            if (inFile) {
                Employee emp(id, name, designation, years_of_service);

                if (Employee::isManagerWithAtLeastTwoYears(emp)) {
                    emp.display();
                    filteredEmployees.push_back(emp); // Save matching employee
                }
            }
        }

        inFile.close();
    } else {
        cout << "Error opening file for reading!\n";
    }

    // ======================= PART B: DELETE UNWANTED (Overwrite with only filtered) ============================
    ofstream cleanFile("employees.txt");
    if (cleanFile.is_open()) {
        cleanFile << "ID,Name,Designation,Years_of_Service\n"; // Write header
        for (const auto& emp : filteredEmployees) {
            emp.writeToFile(cleanFile);
        }
        cleanFile.close();
        cout << "\nDeleted unwanted data, only filtered data remains.\n";
    } else {
        cout << "Error opening file to clean!\n";
    }

    // ======================= PART C: INCREMENT IDs and Years and WRITE ============================
    ofstream updatedFile("updated_employees.txt");
    if (updatedFile.is_open()) {
        updatedFile << "ID,Name,Designation,Years_of_Service\n"; // Write header
        for (auto& emp : filteredEmployees) {
            emp.id += 10; // Increment ID by 10 (you can choose your own logic)
            emp.years_of_service += 1; // Increment service by 1
            emp.writeToFile(updatedFile);
        }
        updatedFile.close();
        cout << "\nWritten updated data with incremented IDs and years to 'updated_employees.txt'.\n";
    } else {
        cout << "Error opening updated file!\n";
    }

    return 0;
}
