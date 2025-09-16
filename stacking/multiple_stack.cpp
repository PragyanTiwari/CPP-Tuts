#include <iostream>
using namespace std;

#define MAX 5

class MultipleStack{

private:
    int arr[MAX];
    int top1, top2;

public:

    // constructor
    MultipleStack(){
        top1 = -1;
        top2 = MAX;
    }

    void push1(int x);
    void push2(int x);
    void pop1();
    void pop2();
    void display1();
    void display2();

};

void MultipleStack::push1(int x){
    if (top1-1 == top2){
        cout << "stack overflow" << endl;
    } else {
        arr[++top1] = x;
        cout << "pushed element using top1" << endl;
    }
}

void MultipleStack::push2(int x){
    if (top2 == top1-1){
        cout << "stack overflow" << endl;
    } else {
        arr[--top2] = x;
        cout << "pushed element using top2" << endl;
    }
}

void MultipleStack::pop1(){
    if (top1 == -1){
        cout << "stack underflow" << endl;
    } else {
        int p = arr[top1--];
        cout << "popped element using top1: " << p << endl;
    }
}

void MultipleStack::pop2(){
    if (top2 == MAX){
        cout << "stack underflow" << endl;
    } else {
        int p = arr[top2++];
        cout << "popped element using top2: " << p << endl;
    }
}

void MultipleStack::display1(){
    if (top1 == -1){
        cout << "stack underflow" << endl;
    } else {
        for (int i = top1; i > -1; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void MultipleStack::display2(){
    if (top2 == MAX){
        cout << "stack underflow" << endl;
    } else {
        for (int i = top2; i < MAX; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}


int main(){
    MultipleStack s;
    s.push1(10);
    s.push2(20);
    s.push1(100);
    s.push2(200);
    s.display1();
    s.display2();
    s.pop1();
    s.pop2();
    s.display1();
    s.display2();
    return 0;
}