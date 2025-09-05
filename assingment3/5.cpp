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
            
        }
        
    }
    int pop(){
        if (isEmpty()){
            cout<<"UNDERFLOW\n";
        } else {
            
            return arr[top--];
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

int evaluatePostfix(string str) {
    stack s;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');
        } else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.pop();
}

int main() {
    string expr;
    cout << "Enter a postfix expression: ";
    cin >> expr;

    cout << "Result = " << evaluatePostfix(expr) << endl;
    return 0;
}