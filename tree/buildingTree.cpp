#include<iostream>
using namespace std;
// building tree 

/*
class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// function to build tree
Node* buildTree(Node* root){
    cout << "enter the data: " << endl;
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    root = new Node(data);
    cout << "enter data for left node of " << data << endl;
    root->left =  buildTree(root->left);

    cout << "enter data for right  node of " << data << endl;
    root->right = buildTree(root->right);
    return root;    
}
int main(){
    Node* root = NULL;
    root = buildTree(root);

}
*/

// ================================ building tree ===============================

class Node {
    public:
        int data;
        Node* left;
        Node* right;
    Node(int d){
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(){
    cout << "enter data for node: " << endl;
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }
    Node* newNode = new Node(data);

    cout << "enter data for left child of " << data << endl;
    newNode->left = buildTree();

    cout << "enter data for right child of " << data << endl;
    newNode->right = buildTree();
    return newNode;
}


int main(){
    Node* root = buildTree();
    
}