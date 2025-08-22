#include <iostream>
using namespace std;


int main() {
    int i,j;
    int max;
    cout<<"Enter number of elements"<<endl;
    cin>>max;
    int arr[max];
    cout<<"Enter array elements( row major)"<<endl;
    for(i=0;i<max;i++){
        int ele;
        cout<<"enter element : ";
        cin>>ele;
        arr[i]=ele;
    }
    int n;
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            if (i==j)
            cout<<" "<<arr[i]<<" ";
        
        else 
        {
            cout<<" "<<0<<" ";
        }
        }
        cout<<"\n";
    }

    
    return 0;
}