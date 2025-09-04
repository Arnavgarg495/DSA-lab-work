#include<iostream>
using namespace std;
int main(){
    int k=0;
    cout<<"enter number of rows/columns: ";
    int n;
    cin>>n;
    cout<<"enter elements: ";
    int arr[(n*(n+1))/2];
    for(int i=0; i<(n*(n+1))/2; i++){
        cin>>arr[i];
    }
    cout<<"lower triangular matrix is: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i>=j){
                cout<<" "<<arr[k]<<" ";
                k++;
            } else cout<<" 0 ";
        } cout<<endl;
    }
}