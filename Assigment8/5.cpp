#include <bits/stdc++.h>
using namespace std;



template<typename T>
void heapify(vector<T> &arr, int n, int i, bool ascending) {
   .
    int extreme = i;      
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (ascending) {
        if (left < n && arr[left] > arr[extreme]) extreme = left;
        if (right < n && arr[right] > arr[extreme]) extreme = right;
    } else {
        if (left < n && arr[left] < arr[extreme]) extreme = left;
        if (right < n && arr[right] < arr[extreme]) extreme = right;
    }

    if (extreme != i) {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, ascending);
    }
}

template<typename T>
void heapSort(vector<T> &arr, bool ascending = true) {
    int n = (int)arr.size();

 
    for (int i = n/2 - 1; i >= 0; --i)
        heapify(arr, n, i, ascending);

    
    for (int i = n - 1; i > 0; --i) {
       
        swap(arr[0], arr[i]);
       
        heapify(arr, i, 0, ascending);
    }
}


int main() {
    vector<int> a = {12, 11, 13, 5, 6, 7};
    cout << "Original: ";
    for (int x : a) cout << x << ' ';
    cout << '\n';

    
    vector<int> b = a;
    heapSort(b, true);
    cout << "Increasing: ";
    for (int x : b) cout << x << ' ';
    cout << '\n';

    vector<int> c = a;
    heapSort(c, false);
    cout << "Decreasing: ";
    for (int x : c) cout << x << ' ';
    cout << '\n';

    return 0;
}
