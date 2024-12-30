#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
//                            =======================traverse======================
void traverse(Node*& head){
    if(head == NULL){
        cout << "No data inserted still" << endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
} 
//                              ================== length of LL =================

int length(Node*& head){
    if(head == NULL){
        return 0;
    }
    int length = 0;
    Node* temp = head;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

//                             =================== Insertion in DLL ================

// insert at head.
void insertAtHead(Node*& head, Node*& tail, int d){
    if(head == NULL){
        Node* newNode = new Node(d);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(d);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return;
}

// insert at end.
void insertAtTail(Node*& head, Node*& tail, int d){
    if(head == NULL){
        Node* newNode = new Node(d);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(d);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    return;
}

// insert at specific postion.
void insertAtPosition(Node*& head, Node*& tail, int pos, int d){
    int len = length(head);
    if(pos > len+1 || pos < 1){
        cout << "enter a valid position to insert " << endl;
        return;
    }
    // at begin
    if(pos == 1){
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    // stop temp at 1 postion before pos.
    while(count < pos-1){
        temp = temp->next;
        count++;
    }
    // at end
    if(temp->next == NULL){
        insertAtTail(head, tail, d);
        return;
    }

    Node* newNode = new Node(d);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

//                              ============= deletion in DLL ================
// delete at head
void deleteAtStart(Node*& head){
    if (head == NULL){
        cout << "List is empty cannot delete " << endl;
        return;
    }
    else{
        Node* temp = head;
        head = temp->next;
        head->prev = NULL;
        temp->next = NULL;

        // free memory for temp;
        delete temp;
    }
    return;
}
// delete at last
void deleteAtLast(Node*& head, Node*& tail){
    // if head is null
    if (head == NULL){
        cout << "List is empty cannot delete " << endl;
        return;
    }

    // if only one element is present in list.
    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }
    Node* temp = head;

    Node* temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete temp;
    return;
}

// delete at postion
void deleteAtPosition(Node*& head, Node*& tail, int pos){
    if(pos == 1){
        deleteAtStart(head);
        return;
    }
    // if postion is invalid.
    int len = length(head);
    if(pos > len || pos < 1){
        cout << "Invalid postion for deletion " << endl;
        return;
    }

    Node* curr = head;
    Node* pre = NULL;
    int count = 1;
    while(count < pos){
        pre = curr;
        curr = curr->next;
        count++;
    }

    if(curr->next == NULL){
        deleteAtLast(head,tail);
        return;
    }
    else{
        pre->next = curr->next;
        curr->next->prev = pre;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
    return;
}

int main(){
    // Node* node1 = new Node(10);
    // Node* head = node1;
    // Node* tail = node1;
    Node* head = NULL;
    Node* tail = NULL;

    cout << "length of node " << length(head) <<endl;
    traverse(head);

    // insertion
    insertAtHead(head, tail, 5);
    cout << "length of node " << length(head) <<endl;
    traverse(head);

    insertAtTail(head, tail,15);
    cout << "length of node " << length(head) <<endl;
    traverse(head);

    insertAtPosition(head, tail, 3, 20);
    cout << "length of node " << length(head) <<endl;
    traverse(head);

    // deletion
    // deleteAtStart(head);
    // cout << "length of node " << length(head) <<endl;
    // traverse(head);

    // deleteAtLast(head, tail);
    // cout << "length of node " << length(head) <<endl;
    // traverse(head);

    // deleteAtPosition(head, tail, 6);
    // cout << "length of node " << length(head) <<endl;
    // traverse(head);

    cout << "head at node " << head->data << endl;
    cout << "tail at node " << tail->data << endl;
    
}