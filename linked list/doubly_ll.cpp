#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

class dll{

private:
    Node* HEAD;

public:
    dll(){HEAD = NULL;}

    void insert(int pos, int val);
    void remove(int pos);
    void display();
    void rev_list();
    void display_rev();
}


void dll::insert(int pos, int val){
    Node *nn = new Node;
    nn->data = val;
    nn->next = NULL;
    nn->prev = NULL;

    if (pos==1 || HEAD==NULL){
        if (HEAD!=NULL){HEAD->prev = nn;}
        nn->next = HEAD;
        HEAD = nn;
    } else {
        Node *temp = HEAD;
        int i = 1;
        while (i<(pos-1) && temp->next != NULL){
            temp = temp->next;
            i++;
        }
        nn->next = temp->next;
        nn->prev = temp;
        if (temp->next != NULL){temp->next->prev = nn;}
        temp->next = nn;
    }
}


void dll::remove(int pos){
    if (HEAD==NULL){cout << "list empty !" << endl; return;}
    Node *temp = HEAD;
    if (pos==1){
        HEAD = HEAD->next;
        if (HEAD != NULL){HEAD->prev = NULL;}
        delete temp;
    } else {
        Node *ptr;
        int i=1;
        while (i<(pos-1) && temp->next != NULL){
            temp = temp->next;
            i++;
        }
        ptr = temp->next;
        if (ptr == NULL){cout << "Position out of range !" << endl; return;}
        temp->next = ptr->next;
        if (ptr->next != NULL){ptr->next->prev = temp;}
        delete ptr;
    }
}


void dll::display(){
    if (HEAD == NULL){cout << "list is empty!" << endl;}
    else{
        Node *temp = HEAD;
        while(temp != NULL){
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}


void dll::display_rev(){
    if (HEAD == NULL){cout << "list is empty!" << endl;}
    else{
        Node *temp = HEAD;
        while(temp->next != NULL){
            temp = temp->next;
        }

        while(temp != NULL){
            cout << temp->data << endl;
            temp = temp->prev;
        }
    }
}


void dll::rev_list(){
    Node *temp, *current;
    temp = NULL;
    current = HEAD;
    while (current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp != NULL){
        HEAD = temp->prev;      // since temp is pointing to the previous node of null
    }
}

