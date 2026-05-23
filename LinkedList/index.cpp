# include <bits/stdc++.h>
using namespace std;


class Node{
    public:
        int data;
        Node* next;
        Node(int val)
        {
            data=val;
            next=NULL;
        }
       
};

void printList(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout << temp->data <<" -> ";
        temp=temp->next;
    }
    cout<< "NULL";
}

Node* insertAtHead(Node* head, int val)
{
    Node* temp=new Node(val);
    temp->next=head;
    head=temp;
    return head;    //Why return head?
    // Because head pointer changes, and we need to update it in the calling function
}

Node* insertAtTail(Node* head, int val){
    Node* temp= new Node(val);
    // Edge case: empty list
    if(head == NULL){
        return temp;
    }
    Node* iterator=head;
    while(iterator->next!=NULL){
        iterator=iterator->next;
    }
    iterator->next=temp;
    return head;
}

Node* deleteHead(Node* head){
    // Edge case
    if(head == NULL) return NULL;

    Node* temp = head;        // store old head
    head = head->next;        // move head

    delete temp;              // free memory

    return head;              // return new head
}

Node* deleteTail(Node* head)
{
    // Edge case: empty list
    if(head == NULL) return NULL;

    // Only one node
    if(head->next == NULL){
        delete head;
        return NULL;
    }

    Node* iterator = head;

    // Go to second last node
    while(iterator->next->next != NULL){
        iterator = iterator->next;
    }

    // Delete last node
    delete iterator->next;

    // Break link
    iterator->next = NULL;

    return head;
}


int main()
{
    Node* head=new Node(5);
    Node* n1=new Node(2);
    Node* n2=new Node(-2);

    head->next=n1;
    n1->next=n2;
    
    printList(head);
    return 0;
}

// What edge cases?


// 1. Empty list
// 2. Single node
// 3. Large list