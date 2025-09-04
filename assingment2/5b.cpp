#include <iostream>
using namespace std;
int main(){
    cout<<"Enter number of rows or column: ";
    int n;
    cin>>n;
    int arr[3*n-2];
    int k=0;
    cout<<"enter the diagonal elements: "<<endl;
    for(int i=0; i<(3*n-2); i++){
        cin>>arr[i];
    }
    cout<<"the tridiagonal elements are: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i-j==-1 || i-j == 0 || i-j == 1){
                cout<<" "<<arr[k]<<" ";
                k++;
            } else cout<<" 0 ";
        } cout<<endl;
    }
   
}
