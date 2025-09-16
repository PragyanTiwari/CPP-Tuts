#include <iostream>
using namespace std;

#define MAX 10

class Stack {

private:
    int arr[MAX];
    int top;

public:

    // constructor
    Stack(){
        top = -1;
    }


    // push 
    void push(int x){
        if (top == MAX-1){
            cout << "stack overflow !" << endl;
        }
        else{
            arr[++top] = x; // increment first, then assign
            cout << "element " << x << " pushed into stack." << endl;
        }
    }

    // pop
    void pop(){
        if (top == -1){
            cout << "stack underflow !" << endl;
        }
        else {
            int popped = arr[top--]; // here first assign , then the value of arr gets decremented..
            cout << "popped from stack." << popped << endl;

        }
    }

    // display top element
    void peek(){
        if (top == -1){cout << "stack empty!" << endl;}
        else{
            cout << "top element: " << arr[top] << endl;
        }
    }

    // display elements
    void display(){
        if (top == -1){cout << "stack empty!" << endl;}
        else{
            for (int i=top; i >= 0; i--){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }


    // count elements
    void count(){
        int total = top + 1;
        cout << "total elements : " << total << endl;
    }
};


int main(){

    Stack s;

    s.pop();
    s.push(10);
    s.push(40);
    s.display();
    s.pop();
    s.display();
    s.count();
    s.peek();

    return 0;
}
