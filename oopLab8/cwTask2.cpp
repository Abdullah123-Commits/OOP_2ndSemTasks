#include <iostream>
#include <vector>
#include <cmath> // For pow
using namespace std;

class Polynomial; // Forward declaration

// Utility class for Polynomial operations
class PolynomialUtils {
public:
    // Evaluate the polynomial at a given point x
    static int evaluate(const Polynomial &p, int x);

    // Compute the derivative of the polynomial
    static Polynomial derivative(const Polynomial &p);
};

class Polynomial {
private:
    vector<int> coefficients; // Coefficients of the polynomial

    // Helper function to trim leading zeros
    void trimZeros() {
        while (!coefficients.empty() && coefficients.back() == 0) {
            coefficients.pop_back();
        }
    }

public:
    // Friend declaration for utility class
    friend class PolynomialUtils;

    // Default constructor (empty polynomial)
    Polynomial() {}

    // Constructor from vector of coefficients
    Polynomial(const vector<int> &coeffs) : coefficients(coeffs) {
        trimZeros();
    }

    // Overload operator+ for addition
    Polynomial operator+(const Polynomial &other) const {
        vector<int> result;
        size_t maxSize = max(coefficients.size(), other.coefficients.size());
        result.resize(maxSize, 0);

        for (size_t i = 0; i < maxSize; i++) {
            int a = (i < coefficients.size()) ? coefficients[i] : 0;
            int b = (i < other.coefficients.size()) ? other.coefficients[i] : 0;
            result[i] = a + b;
        }
        return Polynomial(result);
    }

    // Overload operator- for subtraction
    Polynomial operator-(const Polynomial &other) const {
        vector<int> result;
        size_t maxSize = max(coefficients.size(), other.coefficients.size());
        result.resize(maxSize, 0);

        for (size_t i = 0; i < maxSize; i++) {
            int a = (i < coefficients.size()) ? coefficients[i] : 0;
            int b = (i < other.coefficients.size()) ? other.coefficients[i] : 0;
            result[i] = a - b;
        }
        return Polynomial(result);
    }

    // Overload operator* for multiplication
    Polynomial operator*(const Polynomial &other) const {
        vector<int> result(coefficients.size() + other.coefficients.size() - 1, 0);

        for (size_t i = 0; i < coefficients.size(); i++) {
            for (size_t j = 0; j < other.coefficients.size(); j++) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(result);
    }

    // Overload operator<< for printing
    friend ostream &operator<<(ostream &os, const Polynomial &p) {
        bool isFirst = true;
        for (int i = p.coefficients.size() - 1; i >= 0; i--) {
            int coeff = p.coefficients[i];
            if (coeff != 0) {
                if (!isFirst && coeff > 0) os << " + ";
                else if (coeff < 0) os << " - ";
                
                if (abs(coeff) != 1 || i == 0) os << abs(coeff);
                if (i > 0) os << "x";
                if (i > 1) os << "^" << i;
                
                isFirst = false;
            }
        }
        if (isFirst) os << "0";
        return os;
    }
};

// PolynomialUtils method implementations

int PolynomialUtils::evaluate(const Polynomial &p, int x) {
    int result = 0;
    for (size_t i = 0; i < p.coefficients.size(); i++) {
        result += p.coefficients[i] * pow(x, i);
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial &p) {
    if (p.coefficients.size() <= 1) {
        return Polynomial(); // Derivative of a constant is 0
    }

    vector<int> derivativeCoeffs(p.coefficients.size() - 1);
    for (size_t i = 1; i < p.coefficients.size(); i++) {
        derivativeCoeffs[i - 1] = p.coefficients[i] * i;
    }
    return Polynomial(derivativeCoeffs);
}

// Example usage
int main() {
    Polynomial p1({2, 0, 3}); // Represents 3x^2 + 2
    Polynomial p2({1, 4});    // Represents 4x + 1

    cout << "Polynomial 1: " << p1 << endl;
    cout << "Polynomial 2: " << p2 << endl;

    cout << "p1 + p2 = " << (p1 + p2) << endl;
    cout << "p1 - p2 = " << (p1 - p2) << endl;
    cout << "p1 * p2 = " << (p1 * p2) << endl;

    PolynomialUtils utils;
    int value = PolynomialUtils::evaluate(p1, 2);
    cout << "p1 evaluated at x=2: " << value << endl;

    Polynomial derivative = PolynomialUtils::derivative(p1);
    cout << "Derivative of p1: " << derivative << endl;

    return 0;
}
