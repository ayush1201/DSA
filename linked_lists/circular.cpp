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

void insertNode(Node* &tail,int element,int d){
    //inserting the new node.
    if(tail == NULL){
        //if list is empty
        Node* Newnode = new Node(d);
        tail = Newnode;
        Newnode -> next = Newnode;
    }
    else{
        // assuming taht element is present in list.
        Node* curr = tail;
        while(curr -> data != element){
            curr = curr -> next;
        }
        //now curr pointer is on element.
        Node* temp = new Node(d);
        temp ->next = curr -> next;
        curr -> next = temp;

        

    }
}

void deleteNode(Node* &tail,int d){
    //if list is empty 
    if(tail == NULL){
        cout<<"the list is empty "<<endl;
    }
    else{
    //non empty 
    Node* prev = tail;
    Node* curr = prev -> next;
    while (curr -> data != d )
    {
        prev = curr;
        curr = curr -> next;
       
    }
    prev -> next = curr -> next;
    
    //1 node present
    if(curr == prev){
        tail=NULL;
    }
    //>=2 nodes present.
    else if(tail == curr){
        tail = prev;
    }
    curr -> next =NULL;
    delete curr;
    
    }
}

void print(Node* tail){
    Node* curr = tail;
    if(tail = NULL){
        cout<<"list is empty "<<endl;
        return;
    }
    do{
        cout<<tail ->data<<" ";
        tail = tail -> next;
    }while(tail != curr);
    cout<<endl;
    
    
}


int main(){

    Node* tail = NULL;

    //inserting in empty list
    insertNode(tail,5,3);
    print(tail);
    insertNode(tail,3,5);
    print(tail);
    insertNode(tail,5,7);
    print(tail);

    deleteNode(tail,3);
    print(tail);
    return 0;
}