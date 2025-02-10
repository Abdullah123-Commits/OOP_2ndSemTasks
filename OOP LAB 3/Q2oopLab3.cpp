/*Create a class called Date that includes three pieces of information as instance variables—a month (typeint), a day
(typeint) and a year (typeint). Provide a method displayDate that displays the month, day and year separated by
forward slashes(/).*/

#include <iostream>
#include <cstdlib>
using namespace std;

typedef class Date {
    private:
        int month;
        int day;
        int year;
    public:
        void displayDate(void) {
            cout << "The date is : (format month/day/year) " << month << "/" << day << "/" << year << endl;
            return;
        }

        void setDate(int day, int month, int year) {
            this->day = day;
            this->month = month;
            this->year = year;
            return;
        }

}Date;

int main(int argc, char* argv[]) {
    if (argc == 4) {
        Date date;
        date.setDate(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));
        date.displayDate();
    }
    else {
        cout << "Invalid number of arguments passed to function main!" << endl;
        return 1;
    }
    return 0;
}