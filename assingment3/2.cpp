#include <iostream>
#include <string>
using namespace std;
#define MAX 100
class stack{
    public:
    char arr[MAX];
    int top;

    stack(){
        top = -1;
    }

    void push(char c){
        ++top;
        arr[top] = c;
    }

    char pop (char c){
       return arr[top--];
    }
};

int main(){
    stack s;
    string str = "DataStructures";
    for(int i=0; i<str.length(); i++){
        s.push(str[i]);
    }  
    for(int i = s.top; i>=0; i--){
        cout << s.pop(str[i]);
    }
}