#include <iostream>
using namespace std;
int main(){
    int arr[50];
    int opt;
    int n;


    while(1){
        cout<<"1. CREATE"<<endl;
        cout<<"2. DISPLAY"<<endl;
        cout<<"3. INSERT"<<endl;
        cout<<"4. DELETE"<<endl;
        cout<<"5. LINEAR SEARCH"<<endl;
        cout<<"6. EXIT"<<endl;
        
        cin>>opt;

        switch(opt){
            case 1: {
                cout<<"how many elements: ";
                cin>>n;
                for(int i=0; i<n; i++){
                    cin>>arr[i];
                }
                break;
            }
            case 2: {
                cout<<"your array is: ";
                for(int i=0; i<n; i++){
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
                break;
            }
            case 3: {
                cout<<"enter the number you want to insert: ";
                int p;
                cin>>p;
                cout<<"enter the position: ";
                int pos;
                cin>>pos;
                for(int i=n; i>=pos-1; i--){
                        arr[i]= arr[i-1];
                }
                arr[pos-1] = p;
                n++;
                break;
            }
            case 4: {
                cout<<"enter the number you want to delete: ";
                int q;
                cin>>q;
                cout<<"enter the position: ";
                int pos;
                cin>>pos;
                for(int i = pos-1; i<n; i++){
                    arr[i] = arr[i+1];
                }
                n--;
                break;
            }
            case 5: {
                cout<<"enter the number u want to search: ";
                int x;
                cin>>x;
                int index = -1;
                for(int i=0; i<n; i++){
                    if (arr[i]==x){
                        index = i;
                        break;
                    }
                }
                if(index == -1){
                cout<<"element not found.";
                } else {
                    cout<<"element found at "<<index+1<<"th position";
                }
                break;
            }
            case 6: {
                return 0;
            }
        }
    }
    return 0;
}
