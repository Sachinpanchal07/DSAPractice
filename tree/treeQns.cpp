#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<map>
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
/*
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
*/

// ============================== boundry nodes printing ==============================

/*
// call for left sub tree
void leftPart(Node* root, vector<int> &ans){
    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    }
    ans.push_back(root->data);

    if(root->left){
        leftPart(root->left, ans);
    }
    else{
        leftPart(root->right, ans);
    }
}

// call for leaf nodes
void leafNodes(Node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }
    
    leafNodes(root->left, ans);
    leafNodes(root->right, ans);
}

// call for right sub tree
void rightPart(Node* root, vector<int> &ans){
    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    }
    if(root->right){
        rightPart(root->right, ans);
    }
    else{
        rightPart(root->left, ans);
    }
    ans.push_back(root->data);
}


vector<int> boundry(Node* root){
    vector<int> ans;

    if(root == NULL){
        return ans;
    }
    // add root node in ans
    ans.push_back(root->data);

    // call for left sub tree
    leftPart(root->left, ans);

    // call for leaf nodes
    leafNodes(root->left, ans);
    leafNodes(root->right, ans);

    // call for right sub tree
    rightPart(root->right, ans);
    return ans;
}
*/

vector<int> leftView(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    queue<pair<Node*,int> > q;
    map<int,int> m;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<Node*,int> p = q.front();
        Node* frontNode = p.first;
        int hd = p.second;
        q.pop();
        m[hd] = frontNode->data;
        if(root->left){
            q.push(make_pair(root->left,hd++));
        }
        else{
            q.push(make_pair(root->right,hd++));
        }
    }
    for(auto i: m){
        ans.push_back(i.second);
    }
    return ans;
}

// ================================ Top view of tree ==============================

/*
vector<int> topView(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    map<int,int> topNode; // store HD,node data
    queue<pair<Node*,int>> q; // store node,HD
    q.push(make_pair(root,0)); // root node HD have 0;

    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        Node* frontNode = temp.first;
        int hd = temp.second;
        q.pop();

        // check if node is present in map or not with hd, if not add that in map
        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }

        // call for left and right part
        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    // add ans in vector
    for(auto i: topNode){
        ans.push_back(i.second);
    }
    return ans;
}
*/

// ================================ bottom view of tree ==============================

/*
vector<int> bottomView(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    map<int,int> topNode;
    queue<pair<Node*,int>>q;

    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        Node* frontNode = temp.first;
        int hd = temp.second;
        q.pop();

        topNode[hd] = frontNode->data;

        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    for(auto i:topNode){
        ans.push_back(i.second);
    }
    return ans;
}
*/

// ==================================== left view of tree ===============================

/*
// solve function
void solve(Node* root, vector<int> &ans, int level){
    if(root == NULL){
        return;
    }

    // if level = ans size means we are new level

    if(level == ans.size()){
        ans.push_back(root->data);
    }
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}

vector<int> leftView(Node* root){
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}
*/

// ==================================== right view of tree ===============================

/*
// solve function
void solve(Node* root, vector<int> &ans, int level){
    if(root == NULL){
        return;
    }

    // if level = ans size means we are new level

    if(level == ans.size()){
        ans.push_back(root->data);
    }
    solve(root->right, ans, level+1);
    solve(root->left, ans, level+1);
}

vector<int> leftView(Node* root){
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}
*/

// ==================================== vertical order traveresal ===================================
/*
vector<int> verticalTraversal(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
        map<int,vector<int> > topNode; // vector to store nested nodes.
    queue<pair<Node*,int>> q; // store node,HD
    q.push(make_pair(root,0)); // root node HD have 0;

    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        Node* frontNode = temp.first;
        int hd = temp.second;
        q.pop();

        topNode[hd].push_back(frontNode->data);
        // call for left and right part
        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    // add ans in vector
    for(auto i: topNode){
        for(int j=0; j<i.second.size(); j++){
            ans.push_back(i.second[j]);
        }
    }
    return ans;
}
*/

// ============================== sum of nodes of longest path ============================

/*
void solve(Node* root, int len, int &maxLen, int sum, int &maxSum){
    // means recusion reached to leaf node, check conditions, update variables accordingly
    // base case
    if(root == NULL){ 
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen){
            maxSum = sum;
        }
        return;
    }
    // update variables at each level
    sum = sum + root->data;

    solve(root->left, len+1, maxLen, sum, maxSum);
    solve(root->right, len+1, maxLen, sum, maxSum);
}

int maxSum(Node* root){
    int len = 0;
    int maxLen = 0;
    int sum = 0; 
    int maxSum = 0;

    solve(root, len, maxLen, sum, maxSum);
    return maxSum;
}
*/

// =============================== LCA(longest common ancestor) ================================

/*
Node* lca(Node* root, int n1, int n2){
    // base case
    if( root == NULL){
        return NULL;
    }

    // return node if hit the n1 or n2
    if(root->data == n1 || root->data == n2){
        return root;
    }

    // go in left and right part
    Node* leftAns = lca(root->left, n1, n2);
    Node* rightAns = lca(root->right, n1, n2);

    // check conditions based on left and right ans
    if(leftAns != NULL && rightAns != NULL){
        return root;
    }
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }
    else{
        return NULL;
    }
}
*/

// ================================ K sum paths ==============================

void solve(Node* root, vector<int>path, int k, int &count){
    if(root == NULL){
        return;
    }
    
    // add node in vector array on which u are currently
    path.push_back(root->data);
    
    solve(root->left, path, k, count);
    solve(root->right, path, k, count);

    int sum = 0;
    for(int i=path.size()-1; i>=0; i--){
        sum += path[i];
        if(sum == k){
            count++;
        }
    }
}

int kSumPath(Node* root, int k){
    vector<int> path;
    int count = 0;
    solve(root, path, k, count);
    return count;
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
    // vector<int> a = zigZag(root);
    // for(int i=0; i<a.size(); i++){
    //     cout << a[i] << " ";
    // }

    // print boundry
    // vector<int> result = boundry(root);
    // for(int i=0; i<result.size(); i++){
    //     cout << result[i] << " ";
    // }

    // top view of tree
    // vector<int> result = topView(root);
    // for(int i=0; i<result.size(); i++){
    //     cout << result[i] << " ";
    // }

    // bottom veiw of tree
    // vector<int> result = bottomView(root);
    // for(int i=0; i<result.size(); i++){
    //     cout << result[i] << " ";
    // }

    // left veiw of tree
    // vector<int> result = leftView(root);
    // for(int i=0; i<result.size(); i++){
    //     cout << result[i] << " ";
    // }

    // right veiw of tree
    // vector<int> result = rightView(root);
    // for(int i=0; i<result.size(); i++){
    //     cout << result[i] << " ";
    // }

    // vertical traversal
    // vector<int>result = verticalTraversal(root);
    // for(int i=0; i<result.size(); i++){
    //     cout << result[i] << " ";
    // }
    
    // maxSum
    // int sum = maxSum(root);
    // cout << sum ;

    // lca
    // Node* ans = lca(root, 7, 6);
    // cout << ans->data;

    // K sum paths
    int ans = kSumPath(root, 8);
    cout << "no. of path is " <<  ans;

    // 1 3 4 -1 -1 5 -1 -1 2 6 -1 -1 7 -1 -1 
}