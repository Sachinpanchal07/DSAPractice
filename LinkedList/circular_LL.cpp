#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//                           =============== insertion ===============

// insert at head
void insertAtHead(Node*& head, int d){
    Node* newNode = new Node(d);
    if(head == NULL){
        head = newNode;
        newNode->next = head;
        return;
    }
    else{
        Node* temp = head;
        // traverse temp to last node.
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode; // update head to first node.
    }
}
// insert at last.
void insertAtLast(Node*& head, int d){
    Node* newNode = new Node(d);
    if(head == NULL){
        head = newNode;
        newNode->next = head;
        return;
    }
    else{
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// insert at specific postion.

void insertAtPostion(Node*& head, int d, int pos){
    if(pos <= 0){
        cout << "Invalid position " << endl;
        return;
    }
    if(pos == 1){
        insertAtHead(head,d);
        return;
    }

    Node* newNode = new Node(d);
    Node* temp = head;
    int count = 1;

    while(count < pos-1 && temp->next != head){
        temp = temp->next;
        count++;
    }
    // if pos not found and temp reaches to last element.
    if(temp->next == head && count < pos-1){
        cout << "postion out of range " << endl; 
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

//                             ============== deletion ===============

// delete first node.
void deleteAtStart(Node*& head){
    if(head == NULL){
        cout << "List is empty! can't delete" << endl;
        return;
    }
    // if only one node is present in list.
    else if(head->next == head){
        delete head;
        return;
    }

    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = head->next;
    delete head;
    head = temp->next;
}

// delete at last
void deleteAtLast(Node*& head){
    if (head == NULL) {
        cout << "List is empty, cannot delete" << endl;
        return;
    }
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = head;
}

// delete at specific postion.
void deleteAtPostion(Node*& head, int pos){
    if(head == NULL){
        cout << "list is empty" << endl;
        return;
    }
    if(pos == 1){
        deleteAtStart(head);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count < pos-1 && temp->next != head){
        temp = temp->next;
        count++;
    }

    if(temp->next == head || count < pos-1){
        cout << "Postion out of range " << endl;
        return;
    }

    Node* curr = temp->next;
    temp->next = curr->next;
    delete curr;
    return;
}

// traverse 
void traverse(Node*& head){
    if(head == NULL){
        cout << "List is empty";
        return;
    }
    Node* temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }
    while(temp != head);
}


int main(){
    Node* head = NULL;
    insertAtHead(head,5);
    insertAtLast(head,10);
    insertAtPostion(head,15,2);
    // deleteAtStart(head);
    // deleteAtLast(head);
    deleteAtPostion(head,4);
    traverse(head);
}