#include <iostream>
#include <string>
using namespace std;

int main() {
    int x;
    cout << "Enter number of strings: ";
    cin >> x;

    string arr[x];   
    cout << "Enter " << x << " strings:" << endl;

    for (int i = 0; i < x; i++) {
        cin >> arr[i];
    }


    for (int i = 0; i < x - 1; i++) {
        for (int j = i + 1; j < x; j++) {
            if (arr[i] > arr[j]) {   
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "\nStrings in alphabetical order:" << endl;
    for (int i = 0; i < x; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}