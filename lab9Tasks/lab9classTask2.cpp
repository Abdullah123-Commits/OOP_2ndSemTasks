#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Logger {
private:
    vector<string> logs;       // Stores log messages
    int maxLogs = 1000;        // Max number of logs

    // Private helper function to add log
    void addLog(const string& message) {
        if (logs.size() >= maxLogs) {
            logs.erase(logs.begin()); // Remove oldest log
        }
        logs.push_back(message);
    }

public:
    // Public functions to log different severities
    void logInfo(const string& message, const string& module) {
        addLog("[INFO] [" + module + "] " + message);
    }

    void logWarning(const string& message, const string& module) {
        addLog("[WARNING] [" + module + "] " + message);
    }

    void logError(const string& message, const string& module) {
        addLog("[ERROR] [" + module + "] " + message);
    }

    // Function to get logs (for auditors)
    vector<string> getLogs(string password) {
        if (password == "1234") { // Simple password check
            return logs; // Return copy of logs
        } else {
            cout << "Access denied: wrong password.\n";
            return {};
        }
    }
};

int main() {
    Logger logger;

    // Logs from different parts of the system
    logger.logInfo("Network connected.", "Network");
    logger.logWarning("Slow query detected.", "Database");
    logger.logError("Failed login attempt.", "Auth");
    logger.logError("Disk almost full.", "Storage");

    // Try to access logs
    string pass;
    cout << "Enter password to view logs: ";
    cin >> pass;

    vector<string> logs = logger.getLogs(pass);

    cout << "\n--- LOGS ---\n";
    for (const string& log : logs) {
        cout << log << endl;
    }

    return 0;
}
