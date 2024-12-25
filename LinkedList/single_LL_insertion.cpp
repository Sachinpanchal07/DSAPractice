#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // create pointer of Node type.
    Node(int data)
    {
        this->data = data; // access the data in object in heap memory.
        this->next = NULL;
    }
};
//                           =================== insertion ======================
// insert at head node
void insertAtHead(Node*& head, int d)
{
    Node *newNode = new Node(d);
    newNode -> next = head;
    head = newNode;
}

// insert at tail
void insertAtTail(Node*& tail, int d){
    Node* newNode = new Node(d);
    tail -> next = newNode;
    tail = newNode;
}

// insert at specific postion
void insertATPosition(Node*& head, Node*& tail, int pos, int d){
    Node* temp = head;

    // insert at begin.
    if(pos == 1){
        insertAtHead(head, d);
        return;
    }

    // itrate to before that postition, where we want to add node.
    int count = 1;
    while(count < pos-1){
        temp = temp->next;
        count++;
    }

    // check if pos is last node or not.
    if(temp -> next == NULL){
        insertAtTail(tail, d);
        return;
    }

    // create new node
    Node* newNode = new Node(d);

    // point newNode to next node of position
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

// traverse in singly LL
void traverse(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

//                        ====================== deletion ======================

void deleteNode(){
    
}

int main()
{
    // create a dynamic memeory node.
    Node *node1 = new Node(5);
    Node *head = node1; // head points to first node 
    Node *tail = node1; // tail points to first node intially.

    // insert at head
    // traverse(head);
    // insertAtHead(head, 30);
    // traverse(head);
    // insertAtHead(head, 20);
    // traverse(head);

    // insert at tail
    traverse(head);
    insertAtTail(tail, 10);
    traverse(head);
    insertAtTail(tail, 15);
    traverse(head);

    // insert at specific postion
    insertATPosition(head, tail, 3, 12);
    traverse(head);

}




