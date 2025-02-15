#include<iostream>
using namespace std;

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

// ============================== No. of leaf nodes in tree ==============================
void noOfLeafNodes(Node* root, int &count){
    if(root == NULL){
        return;
    }
    noOfLeafNodes(root->left, count);
    if((root->left == NULL) && (root->right == NULL)){
        count++;
    }
    noOfLeafNodes(root->right, count);
}

// =============================== height of tree =================================
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    // call for left part
    int left = height(root->left);
    // call for right part
    int right = height(root->right);
    int ans = max(left, right) + 1;
    return ans;
}

int main(){
    Node* root = buildTree();

    // no. of leaf nodes
    int count=0;
    noOfLeafNodes(root, count);
    cout << "No. of leaf nodes are " << count << endl;

    // height of tree;
    // cout << "height of tree is " <<   height(root) << endl;

    // 1 3 4 -1 -1 5 -1 -1 2 6 -1 -1 7 -1 -1 
}