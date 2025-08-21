#include <iostream>
using namespace std;

int Linear(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        if (arr[i] != i + 1) 
            return i + 1;
    }
    return n; 
}

int Binary(int arr[], int n) {
    int low = 0, high = n - 2;
    while (low <= high) {
        int mid = low + (high - low) / 2; // overflow-safe
        if (arr[mid] == mid + 1)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low + 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int n = 8; 

    cout << "Missing number (Linear): " << Linear(arr, n) << endl;
    cout << "Missing number (Binary): " << Binary(arr, n) << endl;

    return 0;
}