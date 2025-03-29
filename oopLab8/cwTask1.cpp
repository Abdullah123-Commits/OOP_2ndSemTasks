#include <iostream>
#include <algorithm> // For std::gcd
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    void reduce() {
        int gcd = __gcd(numerator, denominator); // Calculate GCD
        numerator /= gcd;
        denominator /= gcd;

        if (denominator < 0) { // Ensure denominator is positive
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructor
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        reduce(); // Simplify the fraction
    }

    // Arithmetic Operators
    Fraction operator+(const Fraction &other) const {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator-(const Fraction &other) const {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator*(const Fraction &other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator/(const Fraction &other) const {
        if (other.numerator == 0) {
            throw invalid_argument("Division by zero.");
        }
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return Fraction(newNumerator, newDenominator);
    }

    // Relational Operators
    bool operator==(const Fraction &other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction &other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction &other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction &other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    bool operator<=(const Fraction &other) const {
        return !(*this > other);
    }

    bool operator>=(const Fraction &other) const {
        return !(*this < other);
    }

    // Friend I/O Operators
    friend ostream &operator<<(ostream &os, const Fraction &f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    friend istream &operator>>(istream &is, Fraction &f) {
        char slash; // To capture '/'
        is >> f.numerator >> slash >> f.denominator;
        if (f.denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        f.reduce();
        return is;
    }
};

int main() {
    try {
        // Example fractions
        Fraction f1(2, 4), f2(3, 6);

        cout << "Fraction 1: " << f1 << endl;
        cout << "Fraction 2: " << f2 << endl;

        // Arithmetic operations
        cout << "f1 + f2 = " << (f1 + f2) << endl;
        cout << "f1 - f2 = " << (f1 - f2) << endl;
        cout << "f1 * f2 = " << (f1 * f2) << endl;
        cout << "f1 / f2 = " << (f1 / f2) << endl;

        // Relational operations
        cout << "f1 == f2: " << (f1 == f2) << endl;
        cout << "f1 != f2: " << (f1 != f2) << endl;
        cout << "f1 < f2: " << (f1 < f2) << endl;
        cout << "f1 > f2: " << (f1 > f2) << endl;

        // Input/Output
        Fraction f3;
        cout << "Enter a fraction (format: numerator/denominator): ";
        cin >> f3;
        cout << "You entered: " << f3 << endl;

    } catch (const exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}
