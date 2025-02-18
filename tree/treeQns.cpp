#include<iostream>
#include<utility>
#include<vector>
#include<queue>
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
                        // ========== approch 1 ============

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

/*
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
*/

// ============================ Is both tree are identical ==========================

/*
bool isIdentical(Node* r1, Node* r2){
    // base case
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1 == NULL && r2 != NULL){
        return false;
    }
    if(r1 != NULL && r2 == NULL){
        return false;
    }
    // do all operation simultaniously on both trees
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    bool isEqual = r1->data == r2->data;

    if(left && right && isEqual){
        return true;
    }
    else{
        return false;
    }
}
*/

// ============================= Sum tree ============================
/*
pair<bool,int> sumTree(Node* root){
    // base case
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    // handle leaf node
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    // call for left and right part
    pair<bool,int> leftSubTree = sumTree(root->left);
    pair<bool,int> rightSubTree = sumTree(root->right);

    bool leftAns = leftSubTree.first;
    bool rightAns = rightSubTree.first;
    bool condition = root->data == leftSubTree.second + rightSubTree.second;

    // make new pair for return to above nodes.
    pair<bool,int>ans;
    
    if(leftAns && rightAns && condition){
        ans.first = true;
        ans.second = root->data + leftSubTree.second + rightSubTree.second;
    }
    else{
        ans.first = false;
    }
    
    return ans;
}
*/

// ================================ zig-zag or spiral traversal =================================
vector<int>zigZag(Node* root){
    vector<int>result;
    queue<Node*>q;

    if(root == NULL){
        return result;
    }
    q.push(root);
    // maintain flag for detecting direction of traversal.
    bool leftToRight = true;

    // level order traversal
    while(!q.empty()){
        int size = q.size();
        vector<int>ans(size);

        for(int i=0; i<size; i++){
            Node* frontNode = q.front();
            q.pop();
            int index = leftToRight ? i : size - i - 1; // checking the direction
            ans[index] = frontNode->data;

            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
        leftToRight = !leftToRight; // revere the direction

        for(auto i: ans){
            result.push_back(i);
        }
    }
    return result;
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
    // cout << isBalanced(root).first << endl;

    // sum tree
    // cout << sumTree(root).first;

    // zig-zag traversal
    vector<int> a = zigZag(root);
    for(int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }



    // 1 3 4 -1 -1 5 -1 -1 2 6 -1 -1 7 -1 -1 
}