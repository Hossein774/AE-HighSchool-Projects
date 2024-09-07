#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Shop{

public:
	int balance = 500000;
	vector <string> cars = { "Pride", "Samand", "Dena" };
	vector <int> carCount = {1, 2, 1};
	vector <int> Prices = {5000, 9000, 100000};

	bool input();
	bool Buy();
	bool Sell();
};

bool Shop::Buy() {
	cout << "Available Cars:" << endl;
	cout << "1.Pride 5000$, 2.Samand 9000$, 3.Dena 100000$" << endl;

	int input1;
	cin >> input1;

	if (balance >= Prices[input1 - 1]) {
		balance = balance - Prices[input1 - 1];
		carCount[input1 - 1]++;
		return true;
	}
	else {
		return false;
	}
	
}

bool Shop::Sell() {
	cout << "Available Cars:" << endl;
	cout << "1.Pride 5000$, 2.Samand 9000$, 3.Dena 100000$" << endl;
	cout << " Sell benefit is 50%" << endl;

	int input1;
	cin >> input1;

	if (input1 == 1) {
		if (carCount[0] > 0) {
			balance = balance + (Prices[0] * 1.5);
			carCount[0]--;
			return true;
		}
		else {
			return false;
		}
	}
	if (input1 == 2) {
		if (carCount[1] > 0) {
			balance = balance + (Prices[1] * 1.5);
			carCount[1]--;
			return true;
		}
		else {
			return false;
		}
	}
	if (input1 == 3) {
		if (carCount[2] > 0) {
			balance = balance + (Prices[2] * 1.5);
			carCount[2]--;
			return true;
		}
		else {
			return false;
		}
	}
}

bool Shop::input() {
	string input1;
	cin >> input1;
	if (input1 == "Buy") {
		if (Buy()) {
			cout << "You have bought a car!" << endl;
			cout << "Your Balance is now : " << balance << endl;
		}
		else {
			cout << "Your balance is not enough!!" << endl;
			cout << "Your Balance is : " << balance << endl;
		}
	}
	if (input1 == "Sell") {
		if (Sell()) {
			cout << "You have sold a car with 50% benefit!!" << endl;
			cout << "Your Balance is now : " << balance << endl;
		}
		else {
			cout << "You haven't got enough car!!" << endl;
			cout << "Your Balance is : " << balance << endl;
		}
	}
	if (input1 == "Finish") {
		return true;
	}
	return input();
}


int main()
{
	cout << "Welccome to vehical shop!!" << endl;
	cout << "What do you want to do ?!" << endl;
	Shop shop;
	shop.input();
}
