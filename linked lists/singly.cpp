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

void insertAtPosition(Node* &head,int position,int d){
    Node* temp=head;
    int count=1;
    while(count<position-1){
        temp  = temp ->next;
        count++;
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

    insertAtPosition(head,3,15);
    print(head);

    return 0;
}