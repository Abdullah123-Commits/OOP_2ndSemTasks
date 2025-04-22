#include <iostream>
#include <string>

class Wallet {
private:
    double balance;
    double dailyDepositTotal;
    double dailyWithdrawTotal;
    const double dailyDepositLimit;
    const double dailyWithdrawLimit;

public:
    Wallet(double depositLimit = 5000.0, double withdrawLimit = 3000.0)
        : balance(0), dailyDepositTotal(0), dailyWithdrawTotal(0),
          dailyDepositLimit(depositLimit), dailyWithdrawLimit(withdrawLimit) {}

    std::string deposit(double amount) {
        if (amount <= 0)
            return "Deposit amount must be positive.";
        if (dailyDepositTotal + amount > dailyDepositLimit)
            return "Deposit failed: Daily deposit limit exceeded.";

        balance += amount;
        dailyDepositTotal += amount;
        return "Deposit successful. New balance: $" + std::to_string(balance);
    }

    std::string withdraw(double amount) {
        if (amount <= 0)
            return "Withdrawal amount must be positive.";
        if (amount > balance)
            return "Withdrawal failed: Insufficient funds.";
        if (dailyWithdrawTotal + amount > dailyWithdrawLimit)
            return "Withdrawal failed: Daily withdrawal limit exceeded.";

        balance -= amount;
        dailyWithdrawTotal += amount;
        return "Withdrawal successful. New balance: $" + std::to_string(balance);
    }

    double getBalance() const {
        return balance;
    }
};

class User {
private:
    std::string userID;
    std::string name;
    Wallet wallet;

public:
    User(const std::string& id, const std::string& username) : userID(id), name(username) {}

    std::string deposit(double amount) {
        return wallet.deposit(amount);
    }

    std::string withdraw(double amount) {
        return wallet.withdraw(amount);
    }

    void checkBalance() const {
        std::cout << name << "'s balance: $" << wallet.getBalance() << std::endl;
    }

    void getUserInfo() const {
        std::cout << "User: " << name << " | ID: " << userID << std::endl;
    }
};

int main() {
    User user1("U001", "Alice");
    User user2("U002", "Bob");

    std::cout << user1.deposit(2000) << std::endl;
    std::cout << user1.withdraw(1500) << std::endl;
    std::cout << user1.withdraw(1000) << std::endl;  // Might exceed remaining balance

    std::cout << user2.deposit(6000) << std::endl;   // Should fail, exceeds deposit limit
    std::cout << user2.withdraw(100) << std::endl;   // Should fail, no funds

    user1.checkBalance();
    user2.checkBalance();

    return 0;
}
