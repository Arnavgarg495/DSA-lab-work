#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;

    int size = n*(n+1)/2;
    int arr[size];  

    cout << "Enter elements\n";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    cout << "Matrix is:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i >= j)
                cout << arr[i*(i+1)/2 + j] << " ";
            else       
                cout << arr[j*(j+1)/2 + i] << " ";
        }
        cout << endl;
    }

    return 0;
}