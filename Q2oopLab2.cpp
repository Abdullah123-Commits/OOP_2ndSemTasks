/*   You are required to pass a single dimension array to a function (type of the array can be your
choice) and perform add operations to each element. Return the array to the main function after
completion. One small catch is that the arguments and the return type should be void*.   */

#include <iostream>
using namespace std;

void* modifyArray(void* ptr,int size,int addValue) {
    int* ptrTypeint = (int*)ptr;
    for (int i=0; i<size; i++) {
        ptrTypeint[i] += addValue;
    }
    return ptr;
}

int main () {
    int size;
    cout << "Enter the size of array:" <<endl;
    cin >> size;
    int arr[size];
    
    int addValue;
    cout << "Enter the value to be added to each element of the array:" <<endl;
    cin >> addValue;

    
for (int i=0; i<size; i++) {
        arr[i] = 5;
    }

    cout << "Array before addition is:"<< endl;
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    
    void* headPtrOfArr = arr;
    void* savedHeadOfArr = headPtrOfArr;// saved head ptr is for manipulation
    void* modifiedArray = modifyArray(savedHeadOfArr,size,addValue);
    int* resultArray = (int*)modifiedArray;

    cout << "Array after adding:" << addValue << "to each element :" <<endl;

    for (int i=0; i<size; i++) {
        cout << resultArray[i] << " ";
    }
    cout<<endl;


    return 0;
}

