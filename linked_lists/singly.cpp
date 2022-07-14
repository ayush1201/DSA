#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    ~Node(){
        int value=this->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free with data "<<value<<endl;
    }
};
void insertAtHead(Node* &head,int d){
    Node *tmp=new Node(d);
    tmp -> next = head;
    head=tmp;

}
void insertAtTail(Node* &tail,int d){
    Node* tmp=new Node(d);
    tail -> next=tmp;
    tail=tmp;
}

void insertAtPosition(Node* &tail,Node* &head,int position,int d){
    //insert at starting
    if(position==1){
        insertAtHead(head,d);
        return;
    }
    Node* temp=head;
    int count=1;
    
    while(count<position-1){
        temp  = temp ->next;
        count++;
    }

    //inserting at last position.
    if(temp -> next==NULL){
        insertAtTail(tail,d);
        return;
    }

    //creating node for insert d
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp ->next;
    temp -> next=nodeToInsert;
}
//printing linked list
void print(Node* &head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp=temp ->next;
    }
    cout<<endl;
}
//deleting the given node.
void deleteNode(int position,Node* &head){
    if(position==1){
        Node* temp=head;
        head = head->next;
        //memory free
        temp->next=NULL;
        delete temp;
    }
    else{
        //deleting middle or end node.
        Node* prev=NULL;
        Node* curr=head;
        int cnt=1;
        while(cnt < position){
            prev=curr;
            curr=curr -> next;
        }
        prev ->next = curr -> next;
        curr->next=NULL;
        delete curr;
    }
}

int main(){
    //creating new node.
    Node *N1 = new Node(12);

    //cout<<N1->data <<" "<<N1->next;
    //pointing head to created node.
    Node* head = N1;
    Node* tail=N1;
    print(head);

    insertAtHead(head,17);
    print(head);

    insertAtTail(tail,13);
    print(head);

    insertAtTail(tail,10);
    print(head);

    insertAtPosition(tail,head,3,15);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    deleteNode(2,head);
    print(head);

    return 0;
}