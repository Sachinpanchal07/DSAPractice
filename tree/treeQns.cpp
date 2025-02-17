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
/*
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
*/
                           
// ========================= is tree balanced =========================

                        // ========== my approch ============
                    
/*
bool isBalanced(Node* root){
    if (root == NULL){
        return true;
    }

    int l1 = height(root->left);
    int l2 = height(root->right);

    if(abs(l1 - l2) > 1){
        return false;
    }

    isBalanced(root->left);
    isBalanced(root->right);
}
*/
                        // ========== approch 1============

/*
bool isBalanced(Node* root){
    if(root == NULL){
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(left && right && diff){
        return 1;
    }
    else{
        return 0;
    }
}
*/

                        // ========== approch 2 ============

pair<bool,int> isBalanced(Node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    // return pair of t/f , height in every recursion call
    pair<bool,int> left = isBalanced(root->left);
    pair<bool,int> right = isBalanced(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool,int> ans; // make a new pair for return to above node including t/f & height of that node.
    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }

    ans.second = max(left.second, right.second) + 1;
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
    // cout << diameter(root).first << endl;

    // is tree balanced
    cout << isBalanced(root).first << endl;



    // 1 3 4 -1 -1 5 -1 -1 2 6 -1 -1 7 -1 -1 
}