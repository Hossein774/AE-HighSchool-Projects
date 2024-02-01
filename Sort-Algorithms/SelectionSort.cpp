#include <iostream>

using namespace std;

// Selection Sort

int main()
{

	int count;
	int arr[1000];
	int temp = 0;
	int temp2, saveIndex;
	int smallest;

	cin >> count;
	for (int i = 0; i < count; i++) {

		cin >> arr[i];

	}

	for (int i = 0; i < count; i++) {

		smallest = arr[temp];
		saveIndex = temp;

		for (int j = temp; j < count; j++) {

			if (arr[j] < smallest) {

				smallest = arr[j];
				saveIndex = j;

			}

		}

		temp2 = arr[i];
		arr[i] = smallest;
		arr[saveIndex] = temp2;

		temp++;


	}

	cout << endl << endl << endl;

	for (int i = 0; i < count; i++) {

		cout << arr[i] << " ";

	}

	cout << endl;


}


