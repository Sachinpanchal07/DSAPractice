#include<iostream>
#include<utility>
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

// =================================== diameter of tree =============================
                                // ======== approach 1 =======
/*
int diameter(Node* root){
    if (root == NULL){
        return 0;
    }
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1;

    int ans = max(op1, max(op2, op3));
    return ans;
}
*/

                                // ======== approach 2 =======

pair<int,int> diameter(Node* root){
    if(root == NULL){
        pair<int, int> p = make_pair(0,0); // make pair, first is diameter second is height
        return p;
    }

    // recursion call for left and right part.
    pair<int,int> left = diameter(root->left);
    pair<int,int> right = diameter(root->right);

    // calculation of all three posiblities.
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    int d = max(op1, max(op2, op3));
    int h = max(left.second, right.second) + 1;

    pair<int,int> ans = make_pair(d,h);
    return ans;
}                               



int main(){
    Node* root = buildTree();

    // no. of leaf nodes
    // int count=0;
    // noOfLeafNodes(root, count);
    // cout << "No. of leaf nodes are " << count << endl;

    // height of tree
    // cout << "height of tree is " <<   height(root) << endl;

    // diameter of tree
    // cout << "diameter of tree is " << diameter(root); // approch1

    // diameter of tree
    cout << diameter(root).first << endl;



    // 1 3 4 -1 -1 5 -1 -1 2 6 -1 -1 7 -1 -1 
}