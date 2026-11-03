#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *next;
}*head=nullptr,*last=nullptr;

int cnt=0;

void creat(int arr[], int n) {
    head=new Node();
    head->data=arr[0];
    head->next=nullptr;
    last=head;
    for(int i=1;i<n;i++) {
        Node *temp=new Node();
        temp->data=arr[i];
        last->next=temp;
        last=temp;
        temp->next=nullptr;
    }
}

int numberofnodes(Node *p) {
    if(p==nullptr)
        return 0;
    return 1+numberofnodes(p->next);
}

void reverse1(Node *p) { //reverse elements
    int i=0; int a[cnt];
    while(p!=nullptr) {
        a[i++]=p->data;
        p=p->next;
    }
    p=head;
    while(p!=nullptr) {
        p->data=a[--i];
        p=p->next;
    }
}

void reverse2(Node *p) { //reverse linkes
    Node*q=nullptr;
    Node*r=nullptr;
    while(p!=nullptr) {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
}

void reverse3(Node *q,Node *p) {
    if(p==nullptr) {
        head=q;
        return;
    }
    reverse3(p,p->next);
    p->next=q;
}

int main() {
    int Arr[5]={1,2,3,4,5};
    creat(Arr,5);
    cnt=numberofnodes(head);

    // reverse1(head);

    // reverse2(head);

    reverse3(nullptr,head);

    Node *first=head;
    while(first!=nullptr) {
        cout<<first->data<<" ";
        first=first->next;
    }

    while(head!=nullptr) {
        Node *temp=head;
        head=head->next;
        delete temp;
    }
}