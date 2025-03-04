#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class Blend {
public:
    void blendJuice() {
        for (int i = 0; i < 4; i++) {
            cout << "Blending...\n";
        }
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Grinding...\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
};

class JuiceMaker {
private:
    Blend blender;
    Grind grinder;
public:
    void makeJuice() {
        blender.blendJuice();
        grinder.grindJuice();
        cout << "Your Fresh Juice is ready!\n";
    }
};

int main() {
    JuiceMaker jm;
    jm.makeJuice();
    return 0;
}