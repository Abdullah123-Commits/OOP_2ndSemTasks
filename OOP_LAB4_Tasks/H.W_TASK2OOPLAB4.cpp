#include <iostream>
using namespace std;

class Account {
    private:
        double balance;  // Data member to hold the account balance

    public:
        // Constructor to initialize the balance
        Account(double initialBalance) {
            if (initialBalance >= 0) {
                balance = initialBalance;  // Initialize balance with a positive value
            } else {
                balance = 0.0;  // If the initial balance is negative, set it to 0
                cout << "Initial balance cannot be negative. Setting balance to 0." << endl;
            }
        }

        // Function to add money to the account (credit)
        void credit(double amount) {
            if (amount > 0) {
                balance += amount;  // Add the amount to balance
                cout << "Successfully credited " << amount << " to your account." << endl;
            } else {
                cout << "Invalid amount. Please enter a positive amount to credit." << endl;
            }
        }

        // Function to withdraw money from the account (debit)
        void debit(double amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;  // Subtract the amount from balance
                cout << "Successfully debited " << amount << " from your account." << endl;
            } else if (amount > balance) {
                cout << "Insufficient balance for withdrawal." << endl;
            } else {
                cout << "Invalid amount. Please enter a positive amount to debit." << endl;
            }
        }

        // Function to get the current balance
        double getBalance() const {
            return balance;  // Return the current balance
        }
};

int main() {
    // Create an Account object with an initial balance of 1000.0
    Account account1(1000.0);

    // Display current balance
    cout << "Initial Balance: " << account1.getBalance() << endl;

    // Credit 500.0 to the account
    account1.credit(500.0);

    // Display the balance after credit
    cout << "Balance after credit: " << account1.getBalance() << endl;

    // Debit 200.0 from the account
    account1.debit(200.0);

    // Display the balance after debit
    cout << "Balance after debit: " << account1.getBalance() << endl;

    // Try to debit an amount larger than the balance
    account1.debit(2000.0);

    // Display the final balance
    cout << "Final Balance: " << account1.getBalance() << endl;

    return 0;
}
