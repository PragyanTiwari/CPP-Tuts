#include <iostream>
using namespace std;

#define size 10

class Queue{

private:
    int items[size];
    int front, rear;

public:
    Queue(){
        front = -1;
        rear = -1;
    }

    void insert(int x);
    void dequeue();
    void display();
};


void Queue::insert(int x){
    if (rear == size-1){
        cout << "queue is full !" << endl;
    } else {
        if (front == -1) front = 0;

        rear ++ ;
        items[rear] = x;
        cout << "element added to queue !" << endl;
    }
}


void Queue::dequeue(){
    if (front == -1){
        cout << "queue is empty !" << endl;
    } else {
        int element = items[front];
        if (front == rear){
            front = -1;
            rear = -1;
        } else {
            front ++;
        }
        cout << "element dequeued : " << element << endl;
    }
}


void Queue::display(){
    if (front == -1){
        cout << "queue is empty !" << endl;
    } else {
        for (int i = front; i <= rear; i++){
            cout << items[i] << endl;
        }
        cout << endl;
    }
}


int main(){
    Queue q;

    q.insert(5);
    q.insert(10);
    q.insert(20);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}