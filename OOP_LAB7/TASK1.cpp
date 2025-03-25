#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Base class
class Account {
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string* transactionHistory; // Dynamically allocated array
    int historySize;
    int transactionCount;

public:
    // Constructor
    Account(int accNum, double bal, string holderName)
        : accountNumber(accNum), balance(bal), accountHolderName(holderName), historySize(10), transactionCount(0) {
        transactionHistory = new string[historySize]; // Allocate memory
    }

    // Deposit function
    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            addTransaction("Deposit: +" + to_string(amount) + " | Balance: " + to_string(balance));
            cout << "Deposited: " << amount << ". New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw function
    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            addTransaction("Withdrawal: -" + to_string(amount) + " | Balance: " + to_string(balance));
            cout << "Withdrawn: " << amount << ". Remaining balance: " << balance << endl;
        } else {
            cout << "Invalid or insufficient funds for withdrawal!" << endl;
        }
    }

    // Print transaction history
    virtual void PrintStatement() {
        cout << "\nTransaction History for Account: " << accountNumber << endl;
        cout << "---------------------------------------------" << endl;
        for (int i = 0; i < transactionCount; ++i) {
            cout << transactionHistory[i] << endl;
        }
        cout << "---------------------------------------------" << endl;
    }

    // Destructor
    virtual ~Account() {
        delete[] transactionHistory; // Free allocated memory
    }

protected:
    // Add transaction to history
    void addTransaction(const string& transaction) {
        if (transactionCount == historySize) {
            // Resize the array if full
            historySize *= 2;
            string* newHistory = new string[historySize];
            for (int i = 0; i < transactionCount; ++i) {
                newHistory[i] = transactionHistory[i];
            }
            delete[] transactionHistory;
            transactionHistory = newHistory;
        }
        transactionHistory[transactionCount++] = transaction;
    }
};

// Derived class: SavingsAccount
class SavingsAccount : public Account {
    double interestRate;

public:
    SavingsAccount(int accNum, double bal, string holderName, double rate)
        : Account(accNum, bal, holderName), interestRate(rate) {}

    void calculateInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
        addTransaction("Interest: +" + to_string(interest) + " | Balance: " + to_string(balance));
        cout << "Interest added: " << interest << ". New balance: " << balance << endl;
    }
};

int main() {
    // Create accounts
    SavingsAccount savings(101, 5000, "Alice", 5.0); // 5% interest rate

    // Transactions
    savings.deposit(1000);
    savings.withdraw(2000);
    savings.calculateInterest();
    savings.PrintStatement();

    return 0;
}
