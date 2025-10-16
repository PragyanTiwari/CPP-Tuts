#include <iostream>
using namespace std;

// consider real values in place of pointers like temp and head, for better understanding when an operation is performed on it.
struct Node{
    int data;
    Node* next;
};


class LinkedList{

private:
    Node* HEAD;

public:

    LinkedList(){
        HEAD = NULL;
    }

    void insert(int pos, int val);
    void remove(int pos);
    void display();
};


void LinkedList::insert(int pos, int val){

    //  create a new node 
    Node *new_node, *temp;
    new_node = new Node;
    // intitializing its params
    new_node->data = val;
    new_node->next = NULL;

    // insert at the beginning
    if (pos==1 || HEAD==NULL){
        new_node->next = HEAD;
        HEAD = new_node;
    } else {
        temp = HEAD;
        int i=1;
        while (i < (pos-1) && temp->next!=NULL){        // post-1 because, at the end of loop, i already gets incremented.
            temp = temp->next;
            i++;
        }
        new_node->next = temp->next;
        temp->next = new_node;                          // temp carries the memory address of previous one
    }
}


void LinkedList::remove(int pos){
    Node *temp, *ptr;

    if (HEAD == NULL){
        cout << "list is empty !" << endl;
        return;
    } 

    if (pos==1){
        temp = HEAD;
        HEAD = HEAD->next;
        delete temp;
    } else {

        temp = HEAD;
        int i = 1;
        while (i < (pos-1) && temp->next != NULL){
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL){
            cout << "position out of range !" << endl;
            return;
        }

        ptr = temp->next;
        temp->next = ptr->next;
        delete ptr;

    }
}


void LinkedList::display(){
    if (HEAD == NULL){
        cout << "list is empty !" << endl;
    } else {
        Node *temp;
        temp = HEAD;
        while (temp != NULL){
            cout << "data :" << temp->data << endl;
            temp = temp->next;
        }
    }
}


int main(){
    LinkedList ll;
    ll.insert(1,10);
    ll.insert(2,20);
    ll.insert(3,50);
    ll.display();
    ll.remove(3);
    ll.display();
    return 0;
}