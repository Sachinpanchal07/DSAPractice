#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        (*this).data = data;
        (*this).next =  NULL;
    }

};
    void addAtBegin(Node*& head, int data){
        Node* newNode = new Node(data);
        (*newNode).next = head;
        head = newNode;
    }

    void traverse(Node*& head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

int main(){
    Node* node1 = new Node(5);
    Node* head = node1;
    Node* tail = node1;
    addAtBegin(head, 10);
    traverse(head);
} 