#include <iostream>
using namespace std;

// Node class representing a single element in the linked list
class node{
    public:
    int data;      // Value stored in the node
    node * next;   // Pointer to the next node in the sequence

    // Default constructor
    node(){
        next=NULL;
    }
    // Parameterized constructor to initialize node with data
    node(int d){
        data=d;
        next=NULL;
    }
};

// Function to traverse and print all elements of the linked list
void printLL(node * &head){
    node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}

// Function to calculate the total number of nodes in the list
int length(node * &head){
    node * temp=head;
    int count=0;
    //count each node 
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

// Function to add a new node with given data at the tail of the list
void insertatEnd(node * &head,int data){
    // INPUT: 1->2->NULL;
    // RESULT: 1->2->data->NULL;
    node * n=new node(data);
    // If head is NULL 
    if(head==NULL){
        head=n;
        return;
    }
    // Maintain a temp pointer 
    node * temp=head;
    
    // Iterate it to the last node
    while(temp->next!=NULL){
        temp=temp->next;
    }
    // Add the node to the end
    temp->next=n;

}



void insertatStart(node * &head,int data){
    // INPUT: 1->2->NULL;
    // RESULT: data->1->2->NULL;
    // Create a new node, add the existing linked list 
    node * n=new node(data);
    
    n->next=head;
    head=n;

}

// Function to insert a node at a specific index/position
void insertatPos(node * &head,int position,int data){
    // INPUT: 1->3->NULL, data, pos=2;
    // RESULT: 1->data->3->NULL;
    int len=length(head);
    if(position>len){
        insertatEnd(head,data);
        return;
    }
    if(head==NULL){
        insertatStart(head,data);
        return;
    }
    node * n= new node(data);
    node * temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    n->next=temp->next;
    temp->next=n;

}

// Function to find the middle element using Floyd's Cycle-Finding Algorithm (Tortoise and Hare)
// Returns the data of the middle node
int getMiddle(node * &head){
    // Maintain two pointers
    node * fast=head;
    node * slow=fast;
    // fast jumps 2 places meanwhile slow jumps 1 place
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    // slow pointer points to the middle 
    return slow->data;
}







int main() {
    node *head=NULL;
    insertatEnd(head,10);
    insertatEnd(head,20);
    insertatEnd(head,30);
    insertatEnd(head,40);

    insertatStart(head,5);

    // cout<<head->data<<endl;
    printLL(head);

    cout<<"MIDDLE: "<<getMiddle(head)<<endl;
    // head=head->next;
    // cout<<head->data;
    return 0;
}