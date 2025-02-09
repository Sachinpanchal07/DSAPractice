#include<iostream>
#include<queue>
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

// ========================== level order traversal =============================
void levelOrderTraversal(Node*& root){
    queue<Node*>q;
    q.push(root);

    // print until q not empty.
    while(!q.empty()){
        Node* temp = q.front();
        cout << temp->data << " "<< endl;
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

// ================================== inorder traversal(LNR) ===========================
void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    // call for left subtree
    inorderTraversal(root->left);
    // print data
    cout << root->data << " ";
    // call for right subtree
    inorderTraversal(root->right);
}

// ================================= preorder traversal(NLR) ========================
void preorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    // print data
    cout << root->data << " ";
    // call for left subtree
    preorderTraversal(root->left);
    // call for right subtree
    preorderTraversal(root->right);
}

// ================================ postorder traversal(LRN) =========================
void postorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    // call for left part
    postorderTraversal(root->left);
    // call for right part
    postorderTraversal(root->right);
    // print data
    cout << root->data << " ";
}

// ============================ building tree using levevl order traversal ======================
void buildTreeLevelOrderTraversal(Node* &root){
    queue<Node*>q;
    cout << "enter data for root " << endl;
    int rootData;
    cin >> rootData;
    root = new Node(rootData);
    q.push(root);

    while(!q.empty()){
        Node*temp = q.front();
        q.pop();
        // left part data
        cout << "enter data for left of " << temp->data << endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        // right part data
        cout << "enter data for right of " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}
int main(){
    // Node* root = buildTree();
    Node* root;
    // cout << "staarting level order" << endl;
    buildTreeLevelOrderTraversal(root);
    levelOrderTraversal(root);

    // inorderTraversal(root);
    // preorderTraversal(root);
    // postorderTraversal(root);
}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
// 1 3 4 -1 -1 5 -1 -1 2 6 -1 -1 7 -1 -1 