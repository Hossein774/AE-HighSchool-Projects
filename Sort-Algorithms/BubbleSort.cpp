#include <iostream>

using namespace std;

// Bubble Sort

int main()
{

    bool isSwapped = false;
    int count;
    int arr[1000];
    int temp;

    cin >> count;

    for (int i = 0; i < count; i++) {

        cin >> arr[i];

    }
    
    for (int i = 0; i < 1000; i++) {

        for (int j = 0; j < count - 1; j++) {

            if (arr[j + 1] < arr[j]) 
            {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSwapped = true;

            }

        }

        if (!isSwapped) {

            break;

        }

    }

    cout << endl << endl;

    for (int i = 0; i < count; i++) {

        cout << arr[i] << " ";

    }
    cout << endl;

}


