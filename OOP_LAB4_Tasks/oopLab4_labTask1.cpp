#include <iostream>
using namespace std;

class Matrix {
private:
    int numberOfRows;
    int numberOfColumns;
    double** arr2D;

public:
    // Default Constructor
    Matrix() : numberOfRows(0), numberOfColumns(0), arr2D(nullptr) {}

    // Parameterized Constructor
    Matrix(int rows, int columns) : numberOfRows(rows), numberOfColumns(columns) {
        arr2D = new double*[numberOfRows];
        for (int i = 0; i < numberOfRows; i++) {
            arr2D[i] = new double[numberOfColumns]{0}; // Initializes with zero
        }
    }

    // Copy Constructor
    Matrix(const Matrix& other) : numberOfRows(other.numberOfRows), numberOfColumns(other.numberOfColumns) {
        arr2D = new double*[numberOfRows];
        for (int i = 0; i < numberOfRows; i++) {
            arr2D[i] = new double[numberOfColumns];
            for (int j = 0; j < numberOfColumns; j++) {
                arr2D[i][j] = other.arr2D[i][j];
            }
        }
    }

    // Move Constructor
    Matrix(Matrix&& other) noexcept
        : numberOfRows(other.numberOfRows), numberOfColumns(other.numberOfColumns), arr2D(other.arr2D) {
        other.arr2D = nullptr;
        other.numberOfRows = 0;
        other.numberOfColumns = 0;
    }

    // Destructor
    ~Matrix() {
        if (arr2D) {
            for (int i = 0; i < numberOfRows; i++) {
                delete[] arr2D[i];
            }
            delete[] arr2D;
        }
    }

    // Methods to get dimensions
    int getRows() { return numberOfRows; }
    int getColumns() { return numberOfColumns; }

    // Get reference to an element
    double& getSpecificIndexValue(int row, int column) {
        return arr2D[row][column];
    }

    // Fill matrix with a specific value
    void fillMatrixWithAValue(double value) {
        for (int i = 0; i < numberOfRows; i++) {
            for (int j = 0; j < numberOfColumns; j++) {
                arr2D[i][j] = value;
            }
        }
    }

    // Transpose matrix
    Matrix transposeMatrix() {
        Matrix transposed(numberOfColumns, numberOfRows);
        for (int i = 0; i < numberOfRows; i++) {
            for (int j = 0; j < numberOfColumns; j++) {
                transposed.arr2D[j][i] = arr2D[i][j];
            }
        }
        return transposed; // Uses move constructor for efficiency
    }

    // Display matrix
    void displayMatrix() {
        for (int i = 0; i < numberOfRows; i++) {
            for (int j = 0; j < numberOfColumns; j++) {
                cout << arr2D[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a 3x3 matrix
    Matrix mat(3, 3);
    mat.fillMatrixWithAValue(5);
    
    cout << "Original Matrix:\n";
    mat.displayMatrix();

    // Transpose the matrix
    Matrix transposed = mat.transposeMatrix();
    cout << "\nTransposed Matrix:\n";
    transposed.displayMatrix();

    return 0;
}
