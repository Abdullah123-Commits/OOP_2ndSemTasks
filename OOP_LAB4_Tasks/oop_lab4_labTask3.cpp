#include <iostream>
#include <stdexcept>  // For exception handling (e.g., out_of_range)

class DynamicArray {
private:
    int* arr;   // Pointer to the dynamically allocated array
    size_t _size; // Holds the current size of the array

public:
    // Default constructor: Initializes an empty array or an array of size zero.
    DynamicArray() : arr(nullptr), _size(0) {}

    // Parameterized constructor: Accepts an integer n that indicates the array size.
    // Allocates an array of that size and default-initializes all elements to 0.
    DynamicArray(size_t n) : _size(n) {
        arr = new int[_size]();  // Allocate memory and initialize all elements to 0
    }

    // Copy constructor: Performs a deep copy of the array.
    DynamicArray(const DynamicArray& other) : _size(other._size) {
        arr = new int[_size];  // Allocate new memory for the deep copy
        for (size_t i = 0; i < _size; ++i) {
            arr[i] = other.arr[i];  // Copy the elements from the source array
        }
    }

    // Move constructor: Efficiently transfers ownership of the dynamic array from an rvalue object.
    // The source is left in a valid but empty state.
    DynamicArray(DynamicArray&& other) noexcept : arr(other.arr), _size(other._size) {
        other.arr = nullptr;  // Nullify the source pointer (the array is "moved" out)
        other._size = 0;  // Reset the size of the moved-from object
    }

    // Copy assignment operator: Performs deep copy, ensuring no memory leak and handling self-assignment.
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {  // Check for self-assignment
            delete[] arr;  // Free the existing memory
            _size = other._size;
            arr = new int[_size];  // Allocate new memory
            for (size_t i = 0; i < _size; ++i) {
                arr[i] = other.arr[i];  // Deep copy the elements
            }
        }
        return *this;  // Return *this to allow chained assignments
    }

    // Move assignment operator: Transfers ownership of the array from an rvalue object.
    // The source is left in a valid but empty state.
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {  // Check for self-assignment
            delete[] arr;  // Deallocate the existing memory

            arr = other.arr;  // Transfer ownership of the array
            _size = other._size;

            other.arr = nullptr;  // Nullify the source pointer
            other._size = 0;  // Reset the size of the moved-from object
        }
        return *this;
    }

    // Destructor: Deallocates the dynamic array when the object goes out of scope.
    ~DynamicArray() {
        delete[] arr;  // Free the allocated memory
    }

    // Member function to return the size of the array
    size_t size() const {
        return _size;
    }

    // Member function to access an element at a given index
    int& at(int index) {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("Index out of range");  // Error if index is invalid
        }
        return arr[index];  // Return the element at the given index
    }

    // Const version of at() for read-only access to the element
    const int& at(int index) const {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    // Member function to resize the array
    void resize(size_t newSize) {
        if (newSize == _size) return;  // No change if the size is the same

        int* newArr = new int[newSize]();  // Allocate a new array of the new size
        size_t minSize = std::min(_size, newSize);  // Find the smaller size between old and new arrays

        // Copy elements from the old array to the new array
        for (size_t i = 0; i < minSize; ++i) {
            newArr[i] = arr[i];
        }

        delete[] arr;  // Deallocate old array
        arr = newArr;   // Point to the new array
        _size = newSize; // Update the size
    }
};

int main() {
    // Create a DynamicArray object with 5 elements
    DynamicArray arr1(5);

    // Set values in the array
    for (size_t i = 0; i < arr1.size(); ++i) {
        arr1.at(i) = static_cast<int>(i * 10);  // Assigning values 0, 10, 20, 30, 40
    }

    // Print values in arr1
    std::cout << "arr1: ";
    for (size_t i = 0; i < arr1.size(); ++i) {
        std::cout << arr1.at(i) << " ";  // Output: 0 10 20 30 40
    }
    std::cout << std::endl;

    // Copy arr1 to arr2 using copy constructor
    DynamicArray arr2 = arr1;

    std::cout << "arr2 (after copy constructor): ";
    for (size_t i = 0; i < arr2.size(); ++i) {
        std::cout << arr2.at(i) << " ";  // Output: 0 10 20 30 40
    }
    std::cout << std::endl;

    // Move arr1 to arr3 using move constructor
    DynamicArray arr3 = std::move(arr1);

    std::cout << "arr3 (after move constructor): ";
    for (size_t i = 0; i < arr3.size(); ++i) {
        std::cout << arr3.at(i) << " ";  // Output: 0 10 20 30 40
    }
    std::cout << std::endl;

    // Resize arr3 to 8 elements
    arr3.resize(8);
    std::cout << "arr3 (after resizing): ";
    for (size_t i = 0; i < arr3.size(); ++i) {
        std::cout << arr3.at(i) << " ";  // Output: 0 10 20 30 40 0 0 0
    }
    std::cout << std::endl;

    return 0;
}
