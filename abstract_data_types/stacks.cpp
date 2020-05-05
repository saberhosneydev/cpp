#include <iostream>
#define MAX 1000
using namespace std;

class stack{
private:
    int top = 0;
public:
    int arr[MAX]; // Maximum size of Stack
    Stack() {
        top = -1;
    }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool stack::push(int x){
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}
bool Stack::isFull(){
    if (top >= MAX)
    {
        cout << "Stack if FULL FUCKER";
        return true;
    }else {
        return false;
    }
}
int main (){
    Stack fuckSteph = new Stack();
    fuckSteph.push(69);
    fuckSteph.popr();e
    fuckSteph.pop();
    fuckSteph.pop();
    fuckSteph.peek();
    fuckSteph.isFull();
    return     0;
}