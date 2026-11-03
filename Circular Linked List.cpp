#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node*next;
}*head=nullptr;

void create(int arr[],int n) {
   Node *last=nullptr;
    head=new Node();
    head->data=arr[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++) {
        Node *temp=new Node();
        temp->data=arr[i];
        temp->next=last->next;
        last->next=temp;
        last=temp;
    }

}

void display(Node*p) {
    do {
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);

}

int flag=0;
void Rdisplay(Node*p) {
    if (p!=head||flag==0) {
        flag=1;
        cout<<p->data<<" ";
        Rdisplay(p->next);
    }
    flag=0;
}

int length() {
    Node*p=head;
    int length=0;
    do {
        length++;
        p=p->next;
    }while(p!=head);
    return length;
}

void insert(int pos,int value) {
    Node*temp,*p;
    if(pos>length()||pos<0) {
        cout<<"pos out of range"<<endl;
        return;
    }
    if(pos==0) {
        temp=new Node();
        temp->data=value;
        if(head==nullptr) {
            head=temp;
            head->next=head;
        }
        else {
            temp->next=head;
            p=head;
            while(p->next!=head) {
                p=p->next;
            }
            p->next=temp;
            head=temp;
        }
    }
    else {
        temp=new Node();
        temp->data=value;
        p=head;
        for(int i=0;i<pos-1;i++) {
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
    }
}
void Delete(int pos) {
    Node*p=head,*q;
    if (pos>length()||pos<0) {
        cout<<"pos out of range"<<endl;
        return;
    }
    if (pos==0) {
        while(p->next!=head) {
            p=p->next;
        }
        if (p==head) {
            delete p;
            head=nullptr;
        }
        else {
            p->next=head->next;
            delete head;
            head=p->next;
        }

    }
    else {
        for (int i=0;i<pos-2;i++) {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        delete q;

    }
}
int main() {
    int Arr[]={1,2,3,4};
    create(Arr,sizeof(Arr)/sizeof(int));
   // display(head);
    cout<<"Enter the position which you want to insert in  : ";
    int pos; cin>>pos;

    cout<<"Enter The Value: ";
    int value; cin>>value;
    insert(pos,value);

    cout<<"Enter the position which you want to delete: ";
    int pos2; cin>>pos2;

    Delete(pos2);
    Rdisplay(head);

}