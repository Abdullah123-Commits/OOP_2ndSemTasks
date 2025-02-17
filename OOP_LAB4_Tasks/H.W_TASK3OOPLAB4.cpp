#include <iostream>
#include <string>
using namespace std;

class Invoice {
    private:
        string partNumber;        // Part number (instance variable)
        string partDescription;   // Part description (instance variable)
        int quantity;             // Quantity of the item (instance variable)
        double pricePerItem;      // Price per item (instance variable)

    public:
        // Constructor to initialize the four instance variables
        Invoice(string partNum, string partDesc, int qty, double price) {
            partNumber = partNum;
            partDescription = partDesc;
            // If quantity is not positive, set it to 0
            if (qty > 0) {
                quantity = qty;
            } else {
                quantity = 0;
            }

            // If price per item is not positive, set it to 0.0
            if (price > 0.0) {
                pricePerItem = price;
            } else {
                pricePerItem = 0.0;
            }
        }

        // Method to calculate the invoice amount (quantity * price per item)
        double getInvoiceAmount() {
            return quantity * pricePerItem;  // Return the total invoice amount
        }

        // Getter methods to access the private members (optional)
        string getPartNumber() const {
            return partNumber;
        }

        string getPartDescription() const {
            return partDescription;
        }

        int getQuantity() const {
            return quantity;
        }

        double getPricePerItem() const {
            return pricePerItem;
        }
};

int main() {
    // Create an Invoice object with part number "A123", description "Hammer", quantity 5, and price 20.0
    Invoice invoice1("A123", "Hammer", 5, 20.0);

    // Display the invoice details
    cout << "Part Number: " << invoice1.getPartNumber() << endl;
    cout << "Part Description: " << invoice1.getPartDescription() << endl;
    cout << "Quantity: " << invoice1.getQuantity() << endl;
    cout << "Price Per Item: $" << invoice1.getPricePerItem() << endl;

    // Calculate and display the total invoice amount
    cout << "Invoice Amount: $" << invoice1.getInvoiceAmount() << endl;

    // Create an Invoice with invalid quantity and price
    Invoice invoice2("B456", "Drill", -3, -15.0); // Invalid quantity and price

    // Display the invoice details for the second object
    cout << "\nPart Number: " << invoice2.getPartNumber() << endl;
    cout << "Part Description: " << invoice2.getPartDescription() << endl;
    cout << "Quantity: " << invoice2.getQuantity() << endl;
    cout << "Price Per Item: $" << invoice2.getPricePerItem() << endl;

    // Calculate and display the total invoice amount for the second object
    cout << "Invoice Amount: $" << invoice2.getInvoiceAmount() << endl;

    return 0;
}
