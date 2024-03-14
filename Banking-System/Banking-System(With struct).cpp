#include <iostream>
#include <vector>

using namespace std;

struct User {
    string account;
    int money;
};

vector<User>Users;

int indexFinder(vector<User>users, string id) {

    for (int i = 0; i < users.size(); i++) {

        if (users[i].account == id) {

            return i;

        }

    }

    return -1;

}

bool DEPOSIT(vector<User>users, string id, int amount) {

    int index = indexFinder(users, id);

    if (index == -1) {

        User user;
        user.account = id;
        user.money = amount;
        Users.push_back(user);


    }
    else {

        users[index].money += amount;

    }

    return true;

}

int WITHDRAW(vector<User>users, string id, int amount) {

    int index = indexFinder(users, id);

    if (index != -1) {

        if (users[index].money >= amount) {

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

bool BALANCE(vector<User>users, string id) {

    int index = indexFinder(users, id);

    if (index == -1) {

        return false;

    }
    else {

        return true;

    }

}

void getInput() {

    string input;
    string id;
    int amount;

    cin >> input;

    if (input == "DEPOSIT") {

        cin >> id >> amount;
        if (DEPOSIT(Users, id, amount)) {

            cout << "OK!";

        }
        getInput();

    }
    else if (input == "WITHDRAW") {

        cin >> id >> amount;
        int temp = WITHDRAW(Users, id, amount);
        if (temp == 1) {
            int index = indexFinder(Users, id);

            Users[index].money -= amount;
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
        if (BALANCE(Users, id)) {
            int index = indexFinder(Users, id);

            cout << Users[index].money;

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

