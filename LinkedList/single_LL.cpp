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
    // destructor, no need to call manually, if you write "delete temp" your work is done.
    // ~Node(){
    //     // freeup memory.
    //     if(this->next != NULL){
    //         delete next;
    //         this->next = NULL;
    //     }
    // }
};
//                           =================== insertion ======================
// insert at head node
void insertAtHead(Node*& head, Node*& tail, int d)
{
    if(head == NULL){
        Node *newNode = new Node(d);
        head = newNode;
        tail = newNode;
    }
    else{
        Node *newNode = new Node(d);
        newNode -> next = head;
        head = newNode;
    }
    return;
}

// insert at tail
void insertAtTail(Node*& head, Node*& tail, int d){
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        head = newNode;
    }
    else{
        Node* newNode = new Node(d);
        tail -> next = newNode;
        tail = newNode;
    }
    return;
}

// insert at specific postion
void insertATPosition(Node*& head, Node*& tail, int pos, int d){
    Node* temp = head;

    // insert at begin.
    if(pos == 1){
        insertAtHead(head, tail, d);
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
        insertAtTail(head, tail, d);
        return;
    }

    // create new node
    Node* newNode = new Node(d);

    // point newNode to next node of position
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

//                         ====================== traversal ===================

// traverse in singly LL
void traverse(Node*& head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

//                         ====================== deletion ======================

// delete the first node.
void deleteFirstNode(Node*& head){
    Node* temp = head;
    head = head->next;
    delete temp; // freeup memory for temp manually b/z we allocated memory in heap dynamically.
    return;
}

// delete last node.
void deleteLastNode(Node*& head, Node*& tail){
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    tail = temp;
    return;
}

// delete Node of given postion.
void deleteNode(Node*& head, Node*& tail, int pos){
    //  delete first node.
    if(head == NULL){
        return;
    }

    Node* temp = head;
    if(pos == 1){
        deleteFirstNode(head);
        // free memory.
        delete temp; // destructor is called for this.
    }
    else{
        Node* current = head;
        Node* prev = NULL;
        int count = 1;
        while(count < pos){
            prev = current;
            current = current->next;
            count++;
        }
        prev->next = current->next;
        if(prev->next == NULL){
            tail = prev;
        }
        // memory free for current.
        delete current;
    }
    return;
}


int main()
{
    // create a dynamic memeory node.
    // Node *node1 = new Node(5); // divyan doubt ****************************************************
    // Node *head = node1; // head points to first node 
    // Node *tail = node1; // tail points to first node intially.
    Node* head = NULL;
    Node* tail = NULL;

    // insert at head
    // traverse(head);
    // insertAtHead(head,tail, 30);
    // traverse(head);
    // insertAtHead(head,tial, 20);
    // traverse(head);

    // insert at tail
    traverse(head);
    insertAtTail(head, tail, 10);
    traverse(head);
    insertAtTail(head, tail, 15);
    traverse(head);

    // insert at specific postion
    insertATPosition(head, tail, 3, 12);
    traverse(head);

    // delete operations.
    // cout << "delete operations" << endl;
    // deleteNode(head, tail, 4);
    // deleteFirstNode(head,tail);
    // deleteLastNode(head,tail);
    // traverse(head);

}




