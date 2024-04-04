#include <iostream>

using namespace std;

class Date {

private:
    int year, month, day;
    bool isLeap = false;

public:

    void setDate(int inputY, int inputM, int inputD);
    void printDate();
    int getDaysOfThisMonth(int inputM);

};  

int Date::getDaysOfThisMonth(int inputM) {

    if (inputM == 1 || inputM == 3 || inputM ==  5 || inputM == 7 || inputM == 8 || inputM == 10 || inputM == 12) {

        return 31; // 217

    }
    else if (inputM == 4 || inputM == 6 || inputM == 9 || inputM == 11) {

        return 30; // 120

    }
    else {

        if (isLeap) {

            return 29;

        }
        else {

            return 28;

        }

    }

}

void Date::setDate(int inputD, int inputM, int inputY) {

    bool isValid = false;

    if (inputY <= 0) {

        abort();

    }
    else {

        year = inputY;

    }

    if ((inputY % 4) == 0) {

        isLeap = true;

    }
    else if((inputY % 100) == 0) {

        if ((inputY % 400)  == 0) {

            isLeap = true;

        }

    }
    
    if (inputM < 0 || inputM > 12) {

        abort();
        
    }
    else {

        month = inputM;

    }

    if (inputD <= 0 && inputD > getDaysOfThisMonth(inputM)) {

        abort();

    }
    else {

        day = inputD;

    }

}

void Date::printDate() {

    cout << day << " / " << month << " / " << year;

}

int main()
{
    
    int day, month, year;
    Date date;

    cin >> day >> month >> year;

    date.setDate(day, month, year);
    date.printDate();

}

