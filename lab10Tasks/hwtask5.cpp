#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Task {
public:
    string taskInfo;
    bool is_done;

    Task(string info = "", bool done = false) {
        taskInfo = info;
        is_done = done;
    }

    void writeToFile(ofstream &outFile) const {
        outFile << taskInfo << "," << is_done << endl;
    }
};

// Function to read all tasks from the file
void readTasks(vector<Task> &tasks) {
    tasks.clear();
    ifstream inFile("tasks.txt");

    if (inFile.is_open()) {
        string info;
        int done;
        while (getline(inFile, info, ',')) { // Read until comma
            inFile >> done;
            inFile.ignore(); // ignore newline
            tasks.push_back(Task(info, done));
        }
        inFile.close();
    }
}

// Function to display all tasks
void displayTasks(const vector<Task> &tasks) {
    cout << "\nTasks:\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].taskInfo << " [" 
             << (tasks[i].is_done ? "Done" : "Not Done") << "]" << endl;
    }
}

// Function to write all tasks back to the file
void writeAllTasks(const vector<Task> &tasks) {
    ofstream outFile("tasks.txt");

    if (outFile.is_open()) {
        for (const Task &task : tasks) {
            task.writeToFile(outFile);
        }
        outFile.close();
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n--- To-Do List Manager ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string info;
            cout << "Enter task info: ";
            getline(cin, info);
            ofstream outFile("tasks.txt", ios::app);
            if (outFile.is_open()) {
                Task newTask(info, false);
                newTask.writeToFile(outFile);
                outFile.close();
                cout << "Task added successfully!\n";
            } else {
                cout << "Error opening file!\n";
            }
        }
        else if (choice == 2) {
            readTasks(tasks);
            if (tasks.empty()) {
                cout << "No tasks found.\n";
            } else {
                displayTasks(tasks);
            }
        }
        else if (choice == 3) {
            readTasks(tasks);
            if (tasks.empty()) {
                cout << "No tasks found.\n";
            } else {
                displayTasks(tasks);
                cout << "Enter task number to mark as done: ";
                int num;
                cin >> num;
                if (num >= 1 && num <= tasks.size()) {
                    tasks[num - 1].is_done = true;
                    writeAllTasks(tasks);
                    cout << "Task marked as done.\n";
                } else {
                    cout << "Invalid task number.\n";
                }
            }
        }
    } while (choice != 4);

    cout << "Goodbye!\n";
    return 0;
}