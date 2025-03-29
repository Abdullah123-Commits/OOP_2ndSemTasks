#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For reverse
using namespace std;

class BigInteger {
private:
    vector<int> digits; // Store digits (least significant to most significant)
    bool isNegative;    // Store sign of the number

    // Helper function to remove leading zeros
    void trimZeros() {
        while (!digits.empty() && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.empty()) {
            isNegative = false; // Zero is not negative
            digits.push_back(0); // Zero representation
        }
    }

public:
    // Constructors
    BigInteger() : isNegative(false) {
        digits.push_back(0); // Default to zero
    }

    BigInteger(const string &num) {
        isNegative = (num[0] == '-'); // Check for negative sign

        // Extract digits from the string, ignoring the sign
        for (int i = num.size() - 1; i >= isNegative; --i) {
            if (!isdigit(num[i])) {
                throw invalid_argument("Invalid character in number");
            }
            digits.push_back(num[i] - '0');
        }
        trimZeros();
    }

    // Overload operator+ (Addition)
    BigInteger operator+(const BigInteger &other) const {
        if (isNegative == other.isNegative) {
            // Same sign: Perform addition
            BigInteger result;
            result.isNegative = isNegative;
            int carry = 0;

            size_t maxSize = max(digits.size(), other.digits.size());
            result.digits.resize(maxSize);

            for (size_t i = 0; i < maxSize; ++i) {
                int a = (i < digits.size()) ? digits[i] : 0;
                int b = (i < other.digits.size()) ? other.digits[i] : 0;
                int sum = a + b + carry;

                result.digits[i] = sum % 10;
                carry = sum / 10;
            }

            if (carry > 0) {
                result.digits.push_back(carry);
            }
            return result;
        } else {
            // Different signs: Perform subtraction
            return *this - (-other);
        }
    }

    // Overload operator- (Subtraction)
    BigInteger operator-(const BigInteger &other) const {
        if (isNegative != other.isNegative) {
            // Different signs: Perform addition
            return *this + (-other);
        }

        // Same sign: Perform subtraction
        if (abs() < other.abs()) {
            BigInteger result = other - *this;
            result.isNegative = !isNegative;
            return result;
        }

        BigInteger result;
        result.isNegative = isNegative;
        result.digits.resize(digits.size());

        int borrow = 0;
        for (size_t i = 0; i < digits.size(); ++i) {
            int a = digits[i];
            int b = (i < other.digits.size()) ? other.digits[i] : 0;
            int diff = a - b - borrow;

            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }

            result.digits[i] = diff;
        }
        result.trimZeros();
        return result;
    }

    // Overload operator<< (Output)
    friend ostream &operator<<(ostream &os, const BigInteger &bigInt) {
        if (bigInt.isNegative) {
            os << '-';
        }
        for (auto it = bigInt.digits.rbegin(); it != bigInt.digits.rend(); ++it) {
            os << *it;
        }
        return os;
    }

    // Overload operator>> (Input)
    friend istream &operator>>(istream &is, BigInteger &bigInt) {
        string num;
        is >> num;
        bigInt = BigInteger(num);
        return is;
    }

    // Comparison Operators
    bool operator==(const BigInteger &other) const {
        return isNegative == other.isNegative && digits == other.digits;
    }

    bool operator!=(const BigInteger &other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger &other) const {
        if (isNegative != other.isNegative) {
            return isNegative;
        }

        if (digits.size() != other.digits.size()) {
            return (digits.size() < other.digits.size()) != isNegative;
        }

        for (size_t i = digits.size(); i > 0; --i) {
            if (digits[i - 1] != other.digits[i - 1]) {
                return (digits[i - 1] < other.digits[i - 1]) != isNegative;
            }
        }
        return false;
    }

    bool operator>(const BigInteger &other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger &other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInteger &other) const {
        return !(*this < other);
    }

    // Unary minus operator
    BigInteger operator-() const {
        BigInteger result = *this;
        result.isNegative = !isNegative;
        return result;
    }

    // Absolute value
    BigInteger abs() const {
        BigInteger result = *this;
        result.isNegative = false;
        return result;
    }
};

// Example usage
int main() {
    BigInteger num1("-123456789");
    BigInteger num2("987654321");

    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;

    cout << "num1 + num2: " << (num1 + num2) << endl;
    cout << "num1 - num2: " << (num1 - num2) << endl;

    BigInteger num3;
    cout << "Enter a big integer: ";
    cin >> num3;
    cout << "You entered: " << num3 << endl;

    return 0;
}
