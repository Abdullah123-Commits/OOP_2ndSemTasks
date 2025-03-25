#include <iostream>
using namespace std;

// BASE CLASS Currency
class Currency {
    protected:
        double amount;             // Original amount in the given currency
        double convertedAmount;    // To store the equivalent amount in base currency (USD)
        string currencyCode;       // Code of the currency
        string currencySymbol;     // Symbol of the currency
    public:
        // CONSTRUCTOR
        Currency(double amount, string currencyCode, string currencySymbol) : 
            amount(amount), convertedAmount(0), currencyCode(currencyCode), currencySymbol(currencySymbol) {}

        // GETTERS AND SETTERS
        void setAmount(double value) { amount = value; }
        void setCurrencyCode(string value) { currencyCode = value; }
        void setCurrencySymbol(string value) { currencySymbol = value; }
        double getAmount() { return amount; }
        string getCurrencyCode() { return currencyCode; }
        string getCurrencySymbol() { return currencySymbol; }
        double getConvertedAmount() { return convertedAmount; }

        // CONVERT TO BASE
        virtual double convertToBase() {
            double amountToBeConverted, exchangeRate;
            cout << "\nEnter amount to be converted into base system: ";
            cin >> amountToBeConverted;

            // Input validation
            if (amountToBeConverted < 0) {
                cout << "Invalid input. Amount cannot be negative." << endl;
                return 0;
            }

            cout << "Enter exchange rate from your current system to base system i.e. American Dollars: ";
            cin >> exchangeRate;

            // Store the converted amount
            convertedAmount = amountToBeConverted * exchangeRate;
            return convertedAmount;
        }

        // CONVERT TO TARGET CURRENCY
        double convertToTargetCurrency() {
            double amountToBeConverted, exchangeRate;
            string targetCurrency;

            cout << "\nEnter the target currency in which you want to convert your amount: ";
            cin >> targetCurrency;

            cout << "Enter amount to be converted: ";
            cin >> amountToBeConverted;

            // Input validation
            if (amountToBeConverted < 0) {
                cout << "Invalid input. Amount cannot be negative." << endl;
                return 0;
            }

            cout << "Enter the exchange rate from your current system to the target currency: ";
            cin >> exchangeRate;

            // Store the converted value temporarily (not modifying object state)
            double convertedValue = amountToBeConverted * exchangeRate;

            // Display result
            cout << "The equivalent amount in " << targetCurrency << " is: " << convertedValue << endl;
            return convertedValue;
        }

        // DISPLAY FUNCTION
        virtual void displayCurrency() {
            cout << "--------------------------------------------------------------" << endl;
            cout << "Currency Code: " << currencyCode << endl;
            cout << "Currency Symbol: " << currencySymbol << endl;
            cout << "Original Amount: " << amount << endl;
            cout << "Converted Amount (Base Currency - USD): " << convertedAmount << endl;
            cout << "--------------------------------------------------------------" << endl;
        }
};


// DERIVED CLASS #1: DOLLAR
class Dollar : public Currency {
    public:
        // CONSTRUCTOR
        Dollar(double amount) : Currency(amount, "USD", "$") {}

        // OVERRIDING CONVERT TO BASE FUNCTION
        double convertToBase() override {
            double exchangeRate = 1;
            double amountToBeConverted;

            cout << "\nEnter amount to be converted into base system: ";
            cin >> amountToBeConverted;

            // Input validation
            if (amountToBeConverted < 0) {
                cout << "Invalid input. Amount cannot be negative." << endl;
                return 0;
            }

            cout << "Since the base currency is already USD, the converted value will be the same." << endl;

            // Store the converted amount
            convertedAmount = amountToBeConverted * exchangeRate;
            return convertedAmount;
        }
};

// DERIVED CLASS #2: EURO
class Euro : public Currency {
    public:
        // CONSTRUCTOR
        Euro(double amount) : Currency(amount, "EUR", "€") {}

        // OVERRIDING CONVERT TO BASE FUNCTION
        double convertToBase() override {
            double exchangeRate, amountToBeConverted;

            cout << "\nEnter amount in Euro to be converted to base system (USD): ";
            cin >> amountToBeConverted;

            // Input validation
            if (amountToBeConverted < 0) {
                cout << "Invalid input. Amount cannot be negative." << endl;
                return 0;
            }

            cout << "Enter the exchange rate from Euro to USD: ";
            cin >> exchangeRate;

            // Store the converted amount
            convertedAmount = amountToBeConverted * exchangeRate;
            return convertedAmount;
        }
};

// DERIVED CLASS #3: RUPEE
class Rupee : public Currency {
    public:
        // CONSTRUCTOR
        Rupee(double amount) : Currency(amount, "PKR", "Rs") {}

        // OVERRIDING CONVERT TO BASE FUNCTION
        double convertToBase() override {
            double exchangeRate, amountToBeConverted;

            cout << "\nEnter amount in Rupee to be converted to base system (USD): ";
            cin >> amountToBeConverted;

            // Input validation
            if (amountToBeConverted < 0) {
                cout << "Invalid input. Amount cannot be negative." << endl;
                return 0;
            }

            cout << "Enter the exchange rate from Rupee to USD: ";
            cin >> exchangeRate;

            // Store the converted amount
            convertedAmount = amountToBeConverted * exchangeRate;
            return convertedAmount;
        }
};

int main() {
    // Creating objects for different currencies
    Dollar dollar(100);
    Euro euro(200);
    Rupee rupee(300);

    // Displaying details of each currency
    dollar.displayCurrency();
    euro.displayCurrency();
    rupee.displayCurrency();

    // Testing convertToBase functionality
    cout << "\nConverted amount in Dollar to base system: " << dollar.convertToBase() << " USD" << endl;
    cout << "\nConverted amount in Euro to base system: " << euro.convertToBase() << " USD" << endl;
    cout << "\nConverted amount in Rupee to base system: " << rupee.convertToBase() << " USD" << endl;

    // Display updated details to show converted amounts
    cout << "\nUpdated Currency Details After Conversion:" << endl;
    dollar.displayCurrency();
    euro.displayCurrency();
    rupee.displayCurrency();

    // Testing convertToTargetCurrency function
    cout << "\nTesting Conversion to Target Currency:" << endl;
    euro.convertToTargetCurrency();

    return 0;
}

