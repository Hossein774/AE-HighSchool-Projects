#include <iostream>
#include <vector>

using namespace std;

vector <string> account;
vector <int> money;
int index2;
int index3;

bool DEPOSIT(string id, int amount) {

    bool isFound = false;
    int index;

    for (int i = 0; i < account.size(); i++) {

        if (account[i] == id) {

            index = i;
            isFound = true;

        }

    }
    if (isFound) {

        money[index] += amount;

    }
    else {

        account.push_back(id);
        money.push_back(amount);

    }

    return true;

}

int WITHDRAW(string id, int amount) {

    bool isFound = false;
    

    for (int i = 0; i < account.size(); i++) {

        if (account[i] == id) {

            index3 = i;
            isFound = true;

        }

    }

    if (isFound) {

        if (money[index3] >= amount) {

            return 1;

        }
        else {

            return 0;

        }

    }
    else {

        return -1;

    }

}

bool BALANCE(string id) {

    bool isFound = false;

    for (int i = 0; i < account.size(); i++) {

        if (account[i] == id) {

            index2 = i;
            isFound = true;

        }

    }

    if (isFound) {

        return true;

    }
    else {

        return false;

    }

}

void getInput() {

    string input;
    string id;
    int amount;

    cin >> input;

    if (input == "DEPOSIT") {

        cin >> id >> amount;
        if (DEPOSIT(id, amount)) {

            cout << "OK!";

        }
        getInput();

    }
    else if (input == "WITHDRAW") {

        cin >> id >> amount;
        int temp = WITHDRAW(id, amount);
        if (temp == 1) {

            money[index3] -= amount;
            cout << "OK!";

        }
        else if (temp == 0) {

            cout << "Not enough money!";

        }
        else if (temp == -1) {

            cout << "Invalid Account!";

        }
        getInput();

    }
    else if (input == "BALANCE") {

        cin >> id;
        if (BALANCE(id)) {

            cout << money[index2];

        }
        else {

            cout << "Invalid Account";

        }
        getInput();

    }
    else if (input == "FINISH") {

        cout << "Finished!";
        return;

    }
    else {

        cout << "Invalid commend!";
        getInput();

    }

}

int main()
{
    
    getInput();

}

