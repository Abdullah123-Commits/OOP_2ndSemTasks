#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    string movieName;
    cout << "Enter the name of the movie: ";
    cin >> movieName;

    float adultTicketPrice,childTicketPrice;
    cout << "Enter the price of adult's ticket:";
    cin >> adultTicketPrice;

    cout << "Enter the price of child's ticket:";
    cin >> childTicketPrice;

    int adultTicketSold,childTicketSold;
    cout << "Enter the number of adult tickets sold:";
    cin >> adultTicketSold;

    cout << "Enter the number of child tickets sold:";
    cin >> childTicketSold;

    float donationPercentage;
    cout << "Enter the percentage of gross amount to be donated to the charity:";
    cin >> donationPercentage;
    cout << "---------------------------------------------------------------------"<<endl;

    cout << "The Movie Name is................... "<<movieName<<endl;
    int totalTicketSoldCount;
    totalTicketSoldCount = adultTicketSold + childTicketSold;
    cout << "The total count of sold tickets is............. "<<totalTicketSoldCount<<endl;
    float grossAmount = (adultTicketPrice*adultTicketSold)+(childTicketPrice*childTicketSold);
    printf("The Gross Amount generated from the total tickets is:............. %.2f\n",grossAmount);
    printf("The Percentage of the gross amount donated to the local charity is :%.2f\n",donationPercentage);
    float amountDonated;
    amountDonated = (donationPercentage/100)*grossAmount;
    printf("The amount donated to the charity is :................%.2f\n",amountDonated);
    float netSale;
    netSale = grossAmount-amountDonated;
    printf("The net amount is:............%.2f\n",netSale);
    return 0;
}