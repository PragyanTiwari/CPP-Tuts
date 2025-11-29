#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
}

class queue{
private:
    Node* front, rear;

public:
    queue(){
        front = rear = NULL;
    }

    void insert(int x);
    void dequeue();
}

void queue::insert(int x){
    Node *nn = new Node();
    nn->data = x;
    nn->next = NULL;

    if (front = NULL){
        front = rear = nn;
    } else {
        rear->next = nn;
        rear = nn;
    }
    cout << "inserted !" << endl;
}

void queue::dequeue(){
    if (front = NULL){
        cout < "queue empty !" << endl;
        return
    }

    cout << "deleted : " << front->data << endl;
    
    Node *temp = front;
    front = front->next;

    // If queue becomes null, rear should also become NULL
    if (front == NULL){
        rear = NULL;
    }

    delete temp;
}