#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// func for wrting the data
void writeEncodedInFile(fstream &obj, int lengthOfStr, string data)
{
    for (int i = 0; i < lengthOfStr; i++)
    {
        obj << char(data[i] + (i + 1));
    }
    return;
}

// func for reading from the file
void readFromFile(fstream &obj)
{
    string line;
    while (getline(obj, line))
    {
        int lengthOfStr = line.length();
        for (int i = 0; i < lengthOfStr; i++)
        {
            cout << char(line[i] - (i + 1));
        }
    }
    return;
    
}

int main()
{
    fstream myFile;
    myFile.open("cwQ1.txt", ios::out);
    string data;
    int lengthOfStr;
    if (myFile.is_open())
    {
        cout << "Enter the string:" << endl;
        cin >> data;
        lengthOfStr = data.length();

        writeEncodedInFile(myFile, lengthOfStr, data);
        myFile.close();  
    }

    myFile.open("cwQ1.txt", ios::in);
    if (myFile.is_open()) {
        readFromFile(myFile);
    }



    return 0;
}