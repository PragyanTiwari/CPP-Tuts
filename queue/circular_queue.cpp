#include <iostream>
using namespace std;

#define size 10

class CircularQueue{
private:
    int items[size];
    int front, rear;

public:
    
    CircularQueue(){
        front = -1;
        rear = -1;
    }

    void insert(int x);
    void dequeue();
    void display();

};

void CircularQueue::insert(int x){
    if (front == (rear + 1) % size){
        cout << "queue is full !" << endl;
    } else {
        if (front == -1){
            front = 0;
        }
        rear = (rear + 1) % size;
        items[rear] = x;
        cout << "inserted element in queue !" << endl;
    }
}


void CircularQueue::dequeue(){
    if (front == -1){
        cout << "queue is empty" << endl;
    } else {
        int element = items[front];
        cout << "element deleted from queue : " << element << endl;
        if (front == rear){
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }
}


void CircularQueue::display(){
    if (front == -1){
        cout << "queue is empty" << endl;
    } else {
        int i;
        for (i = front; i != rear; i = (i+1)%size){
            cout << items[i] << " ";
        }
        cout << items[i];   // display the rear element also, once the loop is finished.
        cout << endl;
    }
}


int main(){
    CircularQueue q;
    q.insert(10);
    q.insert(20);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}