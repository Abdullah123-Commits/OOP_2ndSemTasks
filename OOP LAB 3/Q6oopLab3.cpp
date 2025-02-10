#include <iostream>
using namespace std;

class Matrix {
private:
    int numberOfRows;
    int numberOfColumns;
    float** arr2D;

public:
    // Constructor
    Matrix(int noOfRows, int noOfColumns) : numberOfRows(noOfRows), numberOfColumns(noOfColumns) {
        arr2D = new float*[numberOfRows];
        for (int i = 0; i < numberOfRows; i++) {
            arr2D[i] = new float[numberOfColumns]();
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < numberOfRows; i++) {
            delete[] arr2D[i];
        }
        delete[] arr2D;
    }

    // Copy Constructor (Deep Copy)
    Matrix(const Matrix& other) : numberOfRows(other.numberOfRows), numberOfColumns(other.numberOfColumns) {
        arr2D = new float*[numberOfRows];
        for (int i = 0; i < numberOfRows; i++) {
            arr2D[i] = new float[numberOfColumns];
            for (int j = 0; j < numberOfColumns; j++) {
                arr2D[i][j] = other.arr2D[i][j];
            }
        }
    }

    // Assignment Operator Overload (Deep Copy)
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            for (int i = 0; i < numberOfRows; i++) {
                delete[] arr2D[i];
            }
            delete[] arr2D;

            numberOfRows = other.numberOfRows;
            numberOfColumns = other.numberOfColumns;
            arr2D = new float*[numberOfRows];
            for (int i = 0; i < numberOfRows; i++) {
                arr2D[i] = new float[numberOfColumns];
                for (int j = 0; j < numberOfColumns; j++) {
                    arr2D[i][j] = other.arr2D[i][j];
                }
            }
        }
        return *this;
    }

    int getNumberOfRows() const {
        return numberOfRows;
    }

    int getNumberOfColumns() const {
        return numberOfColumns;
    }

    void setElementAtSpecificIndex(int i, int j, float newValue) {
        if (i >= numberOfRows || j >= numberOfColumns || i < 0 || j < 0) {
            cout << "Invalid row or column index!" << endl;
            return;
        }
        arr2D[i][j] = newValue;
    }

    void display() const {
        for (int i = 0; i < numberOfRows; i++) {
            for (int j = 0; j < numberOfColumns; j++) {
                cout << arr2D[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix addMatrices(const Matrix& m2) const {
        if (numberOfRows != m2.numberOfRows || numberOfColumns != m2.numberOfColumns) {
            cout << "Matrices cannot be added!" << endl;
            return Matrix(0, 0); // Return an empty matrix to signal error
        }

        Matrix result(numberOfRows, numberOfColumns);
        for (int i = 0; i < numberOfRows; i++) {
            for (int j = 0; j < numberOfColumns; j++) {
                result.arr2D[i][j] = arr2D[i][j] + m2.arr2D[i][j];
            }
        }
        return result;
    }

    Matrix multiplyMatrices(const Matrix& m2) const {
        if (numberOfColumns != m2.numberOfRows) {
            cout << "Matrices cannot be multiplied!" << endl;
            return Matrix(0, 0);  // Return an empty matrix
        }

        Matrix result(numberOfRows, m2.numberOfColumns);
        for (int i = 0; i < numberOfRows; i++) {
            for (int j = 0; j < m2.numberOfColumns; j++) {
                for (int k = 0; k < numberOfColumns; k++) {
                    result.arr2D[i][j] += arr2D[i][k] * m2.arr2D[k][j];
                }
            }
        }
        return result;
    }
};


Matrix createMatrix(int rows, int columns, const float elements[]) {
    Matrix matrix(rows, columns);
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix.setElementAtSpecificIndex(i, j, elements[index++]);
        }
    }
    return matrix;
}


void addAndDisplayMatrices(const Matrix& m1, const Matrix& m2) {
    cout << "Matrix 1:" << endl;
    m1.display();

    cout << "Matrix 2:" << endl;
    m2.display();

    Matrix resultAdd = m1.addMatrices(m2);
    cout << "Matrix after addition:" << endl;
    resultAdd.display();
}



void multiplyAndDisplayMatrices(const Matrix& m1, const Matrix& m2) {

    Matrix resultMul = m1.multiplyMatrices(m2);
    cout << "Matrix after multiplication:" << endl;
    resultMul.display();
}

int main() {
    float elements1[] = {1, 2, 3, 4};
    float elements2[] = {5, 6, 7, 8};

    Matrix m1 = createMatrix(2, 2, elements1);
    Matrix m2 = createMatrix(2, 2, elements2);

    addAndDisplayMatrices(m1, m2);
    cout << endl; // Add a separator
    multiplyAndDisplayMatrices(m1, m2);

    return 0;
}