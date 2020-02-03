#include <iostream>
#define MAX 1000
using namespace std;

//Used to create array within a class then push items to it and Pop method used to get the latest pushed value

class Stack {

private:
    int top;
    int arrX[MAX];

public:
    Stack() {
        top= 0;
    }
    void push(int x);
    int pop();
};

void Stack::push(int x) {
    if(top >= (MAX -1)){
        cout<<"StackOverflow";
        return;
    }
    cout << x << " Pushed Into Stack" << endl;
    arrX[top] = x;
    top++;
}

int Stack::pop(){
    if(top == 0){
        cout << "Stack underflow";
        return 0;
    }
    top--;
    cout <<  arrX[top] << " Popped from stack" << endl;
    return arrX[top];
}



int main (){

Stack x;
x.push(10);
x.push(20);

x.pop();
x.pop();
return 0;
}
