#include <iostream>
#include <string>
using namespace std;
#define MAX 100
class stack{
    char arr[MAX];
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
    void pop(){
        if (isEmpty()){
            cout<<"UNDERFLOW\n";
        } else {
             top--;
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
    string str = "{[()]}";
    for(int i= 0; i<str.length(); i++){
        if (str[i] == '{' || str[i] ==  '[' || str[i] ==  '('){
            s.push(str[i]);
        } else if (str[i] == '}' || str[i] ==  ']'|| str[i] == ')'){
            if ((str[i] == ')' && s.peak() == '(') ||
                (str[i] == '}' && s.peak() == '{') ||
                (str[i] == ']' && s.peak() == '[')){
                s.pop();
            }else {
                cout<<"not balanced\n";
                return 0;
            }
        }
    } cout <<"balanced";
}