#include <iostream>
using namespace std;
#define MAX 5
class stack{
    int arr[MAX];
    int top;
    public:
    stack(){
        top = -1;
    }
    int isEmpty(){
        if (top == -1){
            return 1;
        } else return 0;
    }
    int isFull(){
        if (top == MAX -1){
            return 1;
        } else return 0;
    }
    void push( int p){
        if (isFull()){
            cout<<"OVERFLOW\n";
        } else {
            ++top;
            arr[top]=p;
            cout<<p<<" pushed\n";
        }
        
    }
    void pop(){
        if (isEmpty()){
            cout<<"UNDERFLOW\n";
        } else {
            
            cout<<arr[top--]<<" popped\n";
        }
        
    }
    int peak(){
        if(isEmpty()){
            cout<<"empty stack";
        } else return arr[top];
    }
    void display(){
        int i;
        for(i=top; i>=0; --i){
            cout<<arr[i];
        }
    }
};
int main(){
    stack s;
    int num;
    int val;
    do{
        cout<<"menu: "<<endl;
        cout<<"1. push\n";
        cout<<"2. pop\n";
        cout<<"3. full\n";
        cout<<"4. empty\n";
        cout<<"5. peek\n";
        cout<<"6. display\n";
        cout<<"7. exit\n";
        cin>>num;

        switch (num){

            case 1: cout<<"enter push value: ";
            cin >> val;
            s.push(val);
            break;

            case 2: s.pop();
            break;

            case 3: if(s.isEmpty()){
                cout<<"stack is empty\n";
            } else cout<<"stack isnt emptty\n";
            break;

            case 4: if(s.isFull()){
                cout<<"stack is full\n";
            } else cout<<"stack isnt full\n";
            break;

            case 6: s.display();
            break;

            case 5: s.peak();
            break;

            case 7: cout<<"exiting\n";
            break;

            default: cout<<"invalid number \n";
        } 

       
    }while (num !=7 );
    return 0; 
}