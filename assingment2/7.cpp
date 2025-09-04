#include <iostream>
using namespace std;
int main(){
    cout<<"enter the size of the array: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j= i+1; j<n; j++){
            if(i<j && arr[i]>arr[j]){
                count++;
            }
        }
    }

    cout<<count;
}