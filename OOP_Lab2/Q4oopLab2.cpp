#include <iostream>         // THE PROGRAM IS CREATED AS PER THE REQUIRED OUTPUT
                            //OTHERWISE WE HAVE OPTION TO INITIALIZE OR TAKE THE VALUES FROM THE USER AND
                            // THEN DISPLAY THOSE DETAILS...
#define SIZE 123 
using namespace std; 
typedef struct Employee { 
    int employeeId; 
    string employeeName; 
    float employeeSalary; 
    } Employee; 

    typedef struct organisation { 
        string organisationName; 
        string organisationNumber; 
        Employee E; 
        } organisation;
        
int main() { 
        organisation org; 
        cout << "The size of the Structure organisation: " << SIZE << endl; 
        org.organisationName = "NU-FAST"; 
        cout << "organisationName: " << org.organisationName << endl; 
        org.organisationNumber = "NUFAST123ABC"; 
        cout << "organisationNumber: " << org.organisationNumber << endl; 
        org.E.employeeId = 127; 
        cout << "Employee ID: " << org.E.employeeId << endl; 
        org.E.employeeName = "Linus Sebastian";  
        cout << "Employee Name: " << org.E.employeeName << endl; 
        org.E.employeeSalary = 400000; 
        cout << "employee Salary: " << org.E.employeeSalary << endl; 
        return 0; 
    }