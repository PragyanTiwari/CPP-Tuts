#include <iostream>
using namespace std;

struct Node{
    int data;
    int priority;
    int order;
};

#define size 5

void swap(Node &a, Node &b){
    Node temp = a;
    a = b;
    b = temp;
}


class pqueue{

private:
    Node arr[size];
    int front, rear;

public:

    pqueue(){
        front = -1;
        rear = -1;
    }

    void insert(int d, int p, int o);
    void remove();
    void display();

};


void pqueue::insert(int d, int p, int o){
    if (rear == size-1){
        cout << "queue is full !" << endl;
    } else {
        if (front == -1) front = 0;
        rear++;
        arr[rear].data = d;
        arr[rear].priority = p;
        arr[rear].order = o;

        // sort the elements based on priority & order
        for (int i = front; i <= rear; i++){
            for (int j = i+1; j <= rear; j++){
                if (arr[i].priority > arr[j].priority){
                    swap(arr[i],arr[j]);
                } else {
                    if (arr[i].priority == arr[j].priority){
                        if (arr[i].order > arr[j].order){
                            swap(arr[i],arr[j]);
                        }
                    }
                }
            }
        }
    }
}


void pqueue::remove(){
    if (front == -1){
        cout << "queue is empty !" << endl;
    } else {
        cout << "element removed : " << arr[front].data << endl;
        if (front == rear){
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
}


void pqueue::display(){
    if (front == -1){
        cout << "queue is empty !" << endl;
    } else {
        for (int i = front; i <= rear; i++){
            cout << "data : " << arr[i].data << endl;
            cout << "priority : " << arr[i].priority << endl;
            cout << "order : " << arr[i].order << endl;
            cout << endl;
        }
    }
}


int main(){
    pqueue p;
    p.insert(4,3,5);
    p.insert(3,2,4);
    p.insert(55,1,4);
    p.display();
    p.remove();
    p.display();
    return 0;
}