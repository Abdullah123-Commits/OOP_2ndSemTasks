/*Create a class User with two public fields: int Age and string Name. In the Main method, create an object of class
User and set Name to &quot;Teo&quot; and Age to 24. Then, output to the screen: &quot;My name is {Name} and I&#39;m {Age} years
old.&quot; using object fields for Name and Age.*/

#include <iostream>
#include <cstdlib>
using namespace std;

typedef class User {
    public:
        int age;
        string name;
}User;
int main (int argc, char* argv[]) {
    if (argc == 3) {
        User user1;
        user1.age = atoi(argv[1]);
        user1.name = argv[2];
        cout << "The name is :" << user1.name << " and age is :" << user1.age << endl;
    }
    else {
        cout << "Invalid number of arguments passed to main function" << endl;
        return 1;
    }
    

    return 0;
}