#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
}*head=nullptr,*last=nullptr;


int count(Node*ptr) {
    if(ptr==nullptr) {
        return 0;
    }
    return count(ptr->next)+1;
}

int Sum(Node*ptr) {
    if(ptr==nullptr) {
        return 0;
    }
    return Sum(ptr->next)+ptr->data;
}

int mx=INT32_MIN;
int MaxElement(Node*ptr) {
    if(ptr==nullptr) {
        return INT32_MIN;
    }
    MaxElement(ptr->next);
    if (ptr->data>mx) {
        mx=ptr->data;
    }
    return mx;
}

void Search(Node*ptr,int Key) {
    if(ptr==nullptr) {
        cout<<"Key isnot Founded"<<endl;
        return;
    }
    if(Key==ptr->data) {
        cout<<"Key founded"<<endl;
        return;
    }
    Search(ptr->next,Key);
}

Node *q=nullptr;
void MoveKeytofront(Node*ptr,int Key) {
    if(ptr==nullptr) {
        cout<<"No Move"<<endl;
        return;
    }
    if (ptr->data == Key) {
        if (ptr == head) return;
        q->next = ptr->next;
        if (ptr == last) {
            last = q;
        }
        ptr->next = head;
        head = ptr;
        return;
    }
    q=ptr;
    MoveKeytofront(ptr->next,Key);
}

void AddNodeonfirst(Node*AddNode) {
    cout<<"Enter The New Value: ";
    int value; cin>>value;
    AddNode->data=value;
    AddNode->next=head;
    head=AddNode;
}

void AddNodein_specificplace(Node*AddNodein_place) {
    cout<<"Enter The Place: ";
    int Place; cin>>Place;
    Node*p=head;

    int cnt=0;
    while(p!=nullptr && cnt==Place-1) {
        p=p->next;
        cnt++;
    }
    if (p == nullptr) {
        cout << "Position out of bounds!\n";
        return;
    }

   AddNodein_place->next=p->next;
    p->next=AddNodein_place;

    cout<<"Enter The Value: ";
    int value; cin>>value;
    AddNodein_place->data=value;
}

void Addinlast(Node*Addinlast) {
    cout<<"Enter The New Last Value: ";
    int value; cin>>value;
    Addinlast->data=value;
    Addinlast->next=nullptr;
    last->next=Addinlast;
    last=Addinlast;
}

void Delet(int position) {
   if (position<1) {
       cout<<"Position out of bounds!\n";
       return;
   }
    if(position==1) {
     Node *p=head->next;
        delete head;
        head=p;
    }
    else {
        Node *p=head;
        Node *q=nullptr;
        for(int i=0;i<position-1;i++) {
            q=p;
            p=p->next;
        }
        if(p==nullptr) {
            cout<<"Position out of bounds!\n";
            return;
        }
        q->next=p->next;
        delete p;
    }
}

void CheckSorted(Node*Big,Node*Small) {
    while(Big->next!=nullptr) {
        Small=Big;
        Big=Big->next;
        if (Small->data>Big->data) {
            cout<<"Unsorted Linked List"<<endl;
            return;
        }
    }
    cout<<"Sorted Linked List"<<endl;

}

void Delete_Duplicates(Node*first,Node*second) {
    second=first;
    first=first->next;
    while(first!=nullptr ) {
        if (first->data!=second->data) {
            second=first;
            first=first->next;
        }
        else if(first->data==second->data) {
            second->next=first->next;
            delete first;
            first=second->next;
        }
    }
}

int main() {
    int value;
    while (cin>>value&&value!=-1) {
        Node *temp=new Node();
        temp->data=value;
        temp->next=nullptr;
        if(head==nullptr) {
            head=last=temp;
        }
        else {
            last->next=temp;
            last=temp;
        }
    }

    Node*p=head;
    while(p!=nullptr) {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    cout<<count(head)<<endl;
    cout<<Sum(head)<<endl;
    cout<<MaxElement(head)<<endl;

    Node *Small=nullptr;
    CheckSorted(head,Small);

   int key;
    cout<<"Enter Key: ";
    cin>>key;
    Search(head,key);
    MoveKeytofront(head,key);

    Node *AddNode=new Node();
    AddNodeonfirst(AddNode);

    Node *AddNodein_place=new Node();
    AddNodein_specificplace(AddNodein_place);

    Node *AddNodeinlast=new Node();
    Addinlast(AddNodeinlast);

    cout<<"Enter The Position: ";
    int position; cin>>position;
    Delet(position);

    Delete_Duplicates(head,Small);

    p=head;
    while(p!=nullptr) { //print data
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;

    while(head!=nullptr) { //free memory
        Node *ptr=head;
        head=head->next;
        delete ptr;
    }

}