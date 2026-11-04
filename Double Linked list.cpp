#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    Node* prev;
    int data;
    Node* next;
}*first=nullptr;

void create(int arr[], int n) {
    Node *last;
    first=new Node();
    first->data=arr[0];
    first->prev=first->next=nullptr;
    last=first;
    for(int i=1;i<n;i++) {
        Node* temp=new Node();
        temp->data=arr[i];
        temp->prev=last;
        last->next=temp;
        temp->next=nullptr;
        last=temp;
    }
}

int length() {
    int len=0;
    Node* p=first;
    while(p!=nullptr) {
        len++;
        p=p->next;
    }
    return len;
}

void display() {
    Node* p=first;
    while(p!=nullptr) {
        cout<<p->data<<" ";
        p=p->next;
    }
}

void insert( int pos, int value) {
    if(pos>length()||pos<0) {
        cout<<"pos out of range"<<endl;
        return;
    }
    if(pos==0) {
        Node* temp=new Node();
        temp->data=value;
        temp->prev=nullptr;
        temp->next=first;
        if (first)first->prev=temp;
        first=temp;
    }
    else {
        Node*p=first;
        Node* temp=new Node();
        temp->data=value;
        for(int i=0;i<pos-1;i++) {
            p=p->next;
        }
        temp->prev=p;
        temp->next=p->next;
        p->next->prev=temp;
        p->next=temp;
    }
}

void Delete(int pos) {
    if(pos>=length()||pos<0) {
        cout<<"pos out of range"<<endl;
        return;
    }
    if(pos==0) {
        Node* p=first;
        if(first->next==nullptr) {
            first=nullptr;
            delete p;
        }
        else {
            first=first->next;
            first->prev=nullptr;
            delete p;
        }
    }
    else {
        Node*p=first;
        for(int i=0;i<pos;i++) {
            p=p->next;
        }


        p->prev->next=p->next;
        if(p->next) {
            p->next->prev=p->prev;
        }
        delete p;
    }
}

void reverse() {
    Node* p=first;
    while(p!=nullptr) {
        Node* temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=temp;
        if (p->next == nullptr) {
            p->next = p->prev;
            p->prev = nullptr;
            first = p;
            break;
        }
    }
}

int main() {
int Arr[]={1,2,3,4,5};
    create(Arr,sizeof(Arr)/sizeof(int));

    cout<<"Enter the position which you want to insert in  : ";
    int pos; cin>>pos;

    cout<<"Enter The Value: ";
    int value; cin>>value;
    insert(pos,value);

    cout<<"Enter the position which you want to delete: ";
    int pos2; cin>>pos2;
    Delete(pos2);

    reverse();
    display();

    while(first!=nullptr) {
       Node *pre=first;
        first=first->next;
        delete pre;

    }


}