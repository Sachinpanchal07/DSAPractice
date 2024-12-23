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

// insert at head node
void insertAtHead(Node *&head, int d)
{
    Node *newNode = new Node(d);
    newNode -> next = head;
    head = newNode;
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
}

int main()
{
    // create a dynamic memeory node.
    Node *node1 = new Node(40);
    Node *head = node1;
    traverse(head);
    cout << endl;
    insertAtHead(head, 30);
    traverse(head);
    cout << endl;
    insertAtHead(head, 20);
    traverse(head);
    cout << endl;
    insertAtHead(head, 10);
    traverse(head);
}




