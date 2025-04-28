#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Logger {
private:
    string baseFilename;
    int logCount;
    ofstream currentLog;
    int simulatedFileSize; // Simulated file size in bytes
    const int MAX_FILE_SIZE = 1024 * 1024; // 1MB = 1024 * 1024 bytes

    void rotateLog() {
        currentLog.close();
        string newName = baseFilename + to_string(logCount++) + ".txt";
        ofstream newFile(newName);
        newFile.close();
        currentLog.open(baseFilename + ".txt", ios::out);
        simulatedFileSize = 0; // reset the simulated file size
    }

public:
    Logger(string filename = "log") {
        baseFilename = filename;
        logCount = 1;
        simulatedFileSize = 0;
        currentLog.open(baseFilename + ".txt", ios::out);
        if (!currentLog) {
            cout << "Error opening log file!" << endl;
        }
    }

    ~Logger() {
        if (currentLog.is_open()) {
            currentLog.close();
        }
    }

    void writeLog(string message) {
        int messageSize = message.length(); // Approximate size of message
        if (simulatedFileSize + messageSize > MAX_FILE_SIZE) {
            rotateLog();
        }
        currentLog << message << endl;
        simulatedFileSize += messageSize;
    }
};

int main() {
    Logger logger;

    // Simulate writing logs
    for (int i = 1; i <= 100000; i++) {
        logger.writeLog("This is log message number: " + to_string(i));
    }

    cout << "Logging complete." << endl;
    return 0;
}
