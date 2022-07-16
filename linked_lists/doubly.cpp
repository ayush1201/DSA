//doubly linked list has 3 parameters in the node data,prev pointer,next pointer.
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next ;
    Node* prev ;

    //constructor
    Node(int data){
        this -> data=data;
        this -> prev=NULL;
        this -> next=NULL;
    }
    //destructor
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
    //creating the node which need to be inserted.
    Node* temp=new Node(d);
    temp -> next=head;
    head -> prev=temp;
    head=temp;

}

void insertAtTail(Node* &tail,int d){
    //tail node created as temp
    Node* temp=new Node(d);
    tail -> next=temp;
    temp ->prev=tail;
    tail=temp;


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
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;


}

void deleteNode(int position,Node* &head){
    if(position==1){
        Node* temp=head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        //memory free
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
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}


void print(Node* head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}



int main(){
    
    Node* n1=new Node(10);
    Node* head=n1;
    Node* tail=n1;
    print(head);

    insertAtHead(head,8);
    print(head);

    insertAtTail(tail,12);
    print(head);

    insertAtPosition(tail,head,2,7);
    print(head);

    insertAtPosition(tail,head,1,4);
    print(head);

    insertAtPosition(tail,head,6,20);
    print(head);

    deleteNode(6,head);
    print(head);
    cout<<" head "<<head -> data<<endl;
    cout<<" tail "<<tail -> data<<endl;

    return 0;

}