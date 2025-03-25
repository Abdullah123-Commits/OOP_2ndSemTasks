#include <iostream>         
#include <vector>           
using namespace std;

// BASE CLASS Person
class Person {
    protected:
        string name;        // Name of the person
        string id;          // ID of the person
        string address;     // Address of the person
        string phoneNumber; // Phone number of the person
        string email;       // Email address of the person
    
    public:
        // Constructor
        Person(string name, string id, string address, string phoneNumber, string email)
            : name(name), id(id), address(address), phoneNumber(phoneNumber), email(email) {}
    
        // Getter Functions
        string getName() const { return name; }
        string getId() const { return id; }
        string getAddress() const { return address; }
        string getPhoneNumber() const { return phoneNumber; }
        string getEmail() const { return email; }
    
        // Virtual Functions
        virtual void displayInfo() {
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Address: " << address << endl;
            cout << "Phone Number: " << phoneNumber << endl;
            cout << "Email: " << email << endl;
        }
    
        virtual void updateInfo(string newAddress, string newPhone, string newEmail) {
            address = newAddress;
            phoneNumber = newPhone;
            email = newEmail;
        }
    };
// DERIVED CLASS : Student    

class Student : public Person {
    private:
        vector<string> coursesEnrolled;
        double GPA;
        int enrollmentYear;
    
    public:
        // Constructor
        Student(string name, string id, string address, string phoneNumber, string email, double GPA, int year)
            : Person(name, id, address, phoneNumber, email), GPA(GPA), enrollmentYear(year) {}
    
        // Getter Functions
        double getGPA() const { return GPA; }
        int getEnrollmentYear() const { return enrollmentYear; }
        vector<string> getCoursesEnrolled() const { return coursesEnrolled; }
    
        // Method to enroll in a course
        void enrollCourse(string courseName) {
            coursesEnrolled.push_back(courseName);
        }
    
        // Override display function
        void displayInfo() override {
            Person::displayInfo();
            cout << "GPA: " << GPA << endl;
            cout << "Enrollment Year: " << enrollmentYear << endl;
            cout << "Courses Enrolled: ";
            for (const string &course : coursesEnrolled) {
                cout << course << ", ";
            }
            cout << endl;
        }
    };

// CLASS Course    
class Course {
    private:
        string courseId;
        string courseName;
        int credits;
        string instructor;
        string schedule;
        vector<Student> registeredStudents;  // Stores Student objects instead of IDs
    
    public:
        // Constructor
        Course(string courseId, string courseName, int credits, string instructor, string schedule)
            : courseId(courseId), courseName(courseName), credits(credits), instructor(instructor), schedule(schedule) {}
    
        // Method to register a student
        void registerStudent(const Student &student) {
            registeredStudents.push_back(student);  // Add student object to the vector
            cout << "Student " << student.getName() << " with ID " << student.getId() << " has been registered for " 
                << courseName << "." << endl;
        }
    
        void displayCourseDetails() {
            cout << "Course ID: " << courseId << endl;
            cout << "Course Name: " << courseName << endl;
            cout << "Credits: " << credits << endl;
            cout << "Instructor: " << instructor << endl;
            cout << "Schedule: " << schedule << endl;
            cout << "Registered Students: ";
            for (const Student &student : registeredStudents) {
                cout << student.getName() << " (ID: " << student.getId() << "), ";
            }
            cout << endl;
        }
        // GETTER
        string getCourseName() const { return courseName; }
        
    };


// DERIVED CLASS: Professor
    class Professor : public Person {
        private:
            string department;
            vector<Course> coursesTaught; // Store Course objects instead of strings
            double salary;
        
        public:
            // Constructor
            Professor(string name, string id, string address, string phoneNumber, string email, string department, double salary)
                : Person(name, id, address, phoneNumber, email), department(department), salary(salary) {}
        
            // Getter Functions
            string getDepartment() const { return department; }
            vector<Course> getCoursesTaught() const { return coursesTaught; }
            double getSalary() const { return salary; }
        
            // Add a course taught by the professor
            void addCourse(const Course &course) {
                coursesTaught.push_back(course); // Add Course object to the vector
                cout << "Course " << course.getCourseName() << " has been added to Professor " << name << "'s teaching list." << endl;
            }
        
            // Override display function
            void displayInfo() override {
                Person::displayInfo();
                cout << "Department: " << department << endl;
                cout << "Salary: " << salary << endl;
                cout << "Courses Taught: ";
                for (const Course &course : coursesTaught) {
                    cout << course.getCourseName() << ", "; // Access course name through Course object
                }
                cout << endl;
            }
        };
        
// DERIVED CLASS  : STAFF        
class Staff : public Person {
    private:
        string department;
        string position;
        double salary;
    
    public:
        // Constructor
        Staff(string name, string id, string address, string phoneNumber, string email, string department, string position, double salary)
            : Person(name, id, address, phoneNumber, email), department(department), position(position), salary(salary) {}
    
        // Getter Functions
        string getDepartment() const { return department; }
        string getPosition() const { return position; }
        double getSalary() const { return salary; }
    
        // Override display function
        void displayInfo() override {
            Person::displayInfo();
            cout << "Department: " << department << endl;
            cout << "Position: " << position << endl;
            cout << "Salary: " << salary << endl;
        }
    };
    
// MAIN FUNCTION
int main() {
    // Create objects
    Professor professor("Dr. John", "P001", "456 Elm St", "987-654-3210", "john@example.com", "Computer Science", 90000);
    Course course1("CS101", "Introduction to Programming", 3, "Dr. John", "MWF 10:00-11:00");
    Student student("Alice", "S001", "123 Main St", "123-456-7890", "alice@example.com", 3.8, 2021);

    // Test adding a course to professor's list
    professor.addCourse(course1);

    // Test enrolling a student in a course
    student.enrollCourse(course1.getCourseName());
    course1.registerStudent(student);

    // Display data
    cout << "\nProfessor Info:" << endl;
    professor.displayInfo();

    cout << "\nCourse Info:" << endl;
    course1.displayCourseDetails();

    cout << "\nStudent Info:" << endl;
    student.displayInfo();

    return 0;
}


    
