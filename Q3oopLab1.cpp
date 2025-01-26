#include <iostream>
#define SURCHARGE_VALUE 0.15
using namespace std;

int main() {
    int customerId;
    string customerName;
    int unitConsumed;
    cout<<"Enter customer id:"<<endl;
    cin>>customerId;
    cout<<"Enter customer name:"<<endl;
    cin>>customerName;
    cout<<"Enter unit consumed:"<<endl;
    cin>>unitConsumed;

    float totalAmount=0;
    if (unitConsumed>0 && unitConsumed<=199) {
        totalAmount = unitConsumed*16.20;
    }
    else if (unitConsumed>199 && unitConsumed<300) {
        totalAmount = unitConsumed*20.10;
    }
    else if (unitConsumed>300 && unitConsumed<500) {
        totalAmount = unitConsumed*27.10;
    }
    else if (unitConsumed>=500) {
        totalAmount = unitConsumed*35.90;
    }
    else {
        cout<<"Invalid data entered!"<<endl;
        return 1;
    }
    if (totalAmount>18000) {
        totalAmount += SURCHARGE_VALUE*totalAmount;
    }
    cout<<"The total Amount to be paid by the customer is "<<totalAmount<<endl;
    
    return 0;
}