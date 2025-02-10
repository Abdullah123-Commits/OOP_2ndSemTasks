#include <iostream>
#include <cstdlib>  // For atoi to convert string to int
using namespace std;

class Glass {
public:
    int liquidLevel;

    // Method to simulate drinking from the glass
    void Drink(int milliliters) {
        if (milliliters > liquidLevel) {
            cout << "Not enough liquid in the glass. Only " << liquidLevel << " milliliters available." << endl;
            liquidLevel = 0; // After drinking all, the glass is empty
        } else {
            liquidLevel -= milliliters;
            cout << "The person drank " << milliliters << " milliliters." << endl;
        }

        // Check if the liquid level is less than 100 ml, and refill if necessary
        if (liquidLevel < 100) {
            cout << "Liquid level is below 100 ml, refilling the glass." << endl;
            Refill();
        }
    }

    // Method to refill the glass to 200 ml
    void Refill() {
        liquidLevel = 200;
        cout << "Glass refilled to 200 milliliters." << endl;
    }
};

int main(int argc, char* argv[]) {
    // If no command-line arguments are passed, display an error message and exit.
    if (argc != 2) {
        cout << "Usage: program_name <amount_to_drink_in_milliliters>" << endl;
        return 1;  // Exit the program if arguments are incorrect
    }

    Glass glass;  // Create an object of the Glass class

    // Manually initialize liquidLevel to 200 after the object is created
    glass.liquidLevel = 200;

    // Convert the command-line argument to an integer (amount to drink)
    int amountToDrink = atoi(argv[1]);

    // Process the drinking action
    glass.Drink(amountToDrink);

    return 0;
}
