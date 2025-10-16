#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class cll{

private:
    Node* HEAD;

public:
    dll(){HEAD = NULL;}

    void insert(int pos, int val);
    void remove(int pos);
    void display();
}


void cll::insert(int pos, int val){
    Node *nn = new Node;
    nn->data = val;
    nn->next = NULL;

    if (HEAD==NULL){
        HEAD = nn;
        nn->next = HEAD;
        return;
    }

    Node *temp = HEAD;
    
    if (pos == 1){
        while (temp->next != HEAD){
            temp = temp->next;
        }
        nn->next = temp->next;
        temp->next = nn;
        HEAD = nn;
    } else {
        int i = 1;
        while (i < (pos-1) && temp->next != HEAD){
            temp = temp->next;
            i++;
        }
        nn->next = temp->next;
        temp->next = nn
    }
}


void cll::remove(int pos){
    if (HEAD == NULL){cout << "list is empty !" << endl; return;} 
    Node *temp=HEAD, *ptr;
    if (pos==1){
        while (temp->next != HEAD){
            temp = temp->next;
        }
        if (temp == HEAD){
            delete HEAD;
            HEAD = NULL;
        } else {
            temp->next = HEAD->next;
            ptr = HEAD;
            HEAD = HEAD->next;
            delete ptr;
        }
    } else {
        int i=1;
        while (i < (pos-1) && temp->next != HEAD){
            temp = temp->next;
            i++;
        }
        ptr = temp->next;
        temp->next = ptr->next;
        delete ptr;
    }
}



cll::display(){
    if (HEAD==NULL){cout << "empty";}
    else {
        Node *temp = HEAD;
        do{
            cout << temp->data << endl;
            temp = temp->next;
        } while (temp != HEAD)
    }
}