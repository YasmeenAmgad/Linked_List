#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
}*first=nullptr,*second=nullptr,*third=nullptr;

void creat(int arr[], int n) {
    Node*last=nullptr;

    first=new Node();
    first->data=arr[0];
    first->next=nullptr;
    last=first;
    for(int i=1;i<n;i++) {
        Node *temp=new Node();
        temp->data=arr[i];
        last->next=temp;
        last=temp;
        temp->next=nullptr;
    }
}

void creat2(int arr[], int n) {
    Node*last=nullptr;

    second=new Node();
    second->data=arr[0];
    second->next=nullptr;
    last=second;
    for(int i=1;i<n;i++) {
        Node *temp=new Node();
        temp->data=arr[i];
        last->next=temp;
        last=temp;
        temp->next=nullptr;
    }
}

void cocatenation(Node *p) {
    while (p->next!=nullptr) {
        p=p->next;
    }
    p->next=second;
    delete second;
}

void Merge(Node *p,Node *q) {
    Node *last=nullptr;
    if (p->data<=q->data) {
        third=last=p;
        p=p->next;
        last->next=nullptr;
    }
    else {
        third=last=q;
        q=q->next;
        last->next=nullptr;
    }
    while (p!=nullptr&&q!=nullptr) {
        if (p->data<=q->data) {
            last->next=p;
            last=p;
            p=p->next;
            last->next=nullptr;
        }
        else {
            last->next=q;
            last=q;
            q=q->next;
            last->next=nullptr;
        }
    }
    if (p!=nullptr) last->next=p;

    else last->next=q;
}



int main() {
    int Arr1[]={1,2,35,45};
    int Arr2[]={3,4,40,50,55};
    creat(Arr1,sizeof(Arr1)/sizeof(Arr1[0]));
    creat2(Arr2,sizeof(Arr2)/sizeof(Arr2[0]));
    // cocatenation(first);
    Merge(first,second);

    Node *p=third;
    while (p!=nullptr) {
        cout<<p->data<<" ";
        p=p->next;
    }

    while(first!=nullptr) {
        Node *ptr=first;
        first=first->next;
        delete ptr;
    }



    return 0;
}
