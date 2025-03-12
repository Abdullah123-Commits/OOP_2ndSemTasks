#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(const string& accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " into account " << accountNumber << "\n";
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from account " << accountNumber << "\n";
        } else {
            cout << "Insufficient funds in account " << accountNumber << "\n";
        }
    }

    virtual void endOfMonthProcess() {}
    virtual void display() const {
        cout << "Account: " << accountNumber << ", Balance: " << balance << "\n";
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
    double interestRate;

public:
    SavingsAccount(const string& accNum, double initialBalance, double rate)
        : BankAccount(accNum, initialBalance), interestRate(rate) {}

    void endOfMonthProcess() override {
        balance += balance * interestRate;
        cout << "Interest added to account " << accountNumber << "\n";
    }
};

class CheckingAccount : public BankAccount {
    double overdraftLimit;

public:
    CheckingAccount(const string& accNum, double initialBalance, double limit)
        : BankAccount(accNum, initialBalance), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (balance - amount >= -overdraftLimit) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " (Overdraft OK)\n";
        } else {
            cout << "Overdraft limit reached for account " << accountNumber << "\n";
        }
    }
};

class BusinessAccount : public BankAccount {
    double taxRate;

public:
    BusinessAccount(const string& accNum, double initialBalance, double tax)
        : BankAccount(accNum, initialBalance), taxRate(tax) {}

    void deposit(double amount) override {
        double tax = amount * taxRate;
        balance += (amount - tax);
        cout << "Deposited: " << amount - tax << " after tax in account " << accountNumber << "\n";
    }
};
