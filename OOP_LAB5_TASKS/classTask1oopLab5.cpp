#include <iostream>
using namespace std;

class Engine {
    private:
        bool isRunning;
    public:
        // Constructor
        Engine() : isRunning(false) {}
        
        // Start Engine function
        void start() {
            if (!isRunning) {
                isRunning = true;
                cout << "Engine started..." << endl;
            } else {
                cout << "Engine is already running..." << endl;
            }
        }
        
        // Stop Engine function
        void stop() {
            if (isRunning) {
                isRunning = false;
                cout << "Engine stopped..." << endl;
            } else {
                cout << "Engine is already stopped..." << endl;
            }
        }
};

class Car {
    private:
        Engine engine;
    public:
        // Start Car function
        void startCar() {
            engine.start();
        }
        
        // Stop Car function
        void stopCar() {
            engine.stop();
        }
};

int main() {
    Car testObj;
    testObj.startCar();
    testObj.stopCar();
    
    return 0;
}
