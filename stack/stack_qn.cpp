#include<iostream>
// #include<stack>
using namespace std;

// ================================ two stack using single array ===========================
/*
class Stack{
    private:
    int *arr;
    int capacity;
    int top1;
    int top2;

    public:
    Stack(int size){
        capacity = size;
        top1 = -1;
        top2 = size;
        arr = new int[capacity];
    }

    // behavious 
    void push1(int data){
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = data;
        }
        else{
            cout << "stack overflow";
        }
    }

    void push2(int data){
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = data;
        }
        else{
            cout << "stack overflow";
        }
    }

    int pop1(){
        if(top1 >= 0){
            int el = arr[top1];
            top1--;
            return el;
        }
        else{
            return -1;
        }
    }

    int pop2(){
        if(top2 <= capacity){
            int el = arr[top2];
            top2++;
            return el;
        }
        else{
            return -1;
        }
    }
};
*/

// =============================== delete mid element from stack ==========================
// solve function
/*
void solve(stack<int>s, int size, int count){
    if(count == size/2){
        s.pop();
        return;
    }
    int save = s.top();
    s.pop();

    // recursize call
    solve(s, size, count++);

    s.push(save);
}

void deleteMid(stack<int>s, int size){
    int count = 0;
    solve(stack<int>s, size, count);
}
*/

// ======================= valid parenthesis ====================
/*
bool isvalidparenthesis(stack<char>s, chart str){
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        // if opening bracekt then add to stack
        if(ch == "(" || ch == "{" || ch == "["){
            stack.push(ch);
        }
        // if closing bracket then compare with opening bracket in stack.
        else{
            if(!s.empty()){
                char top = stack.top();
                if(top == "(" && ch == ")" || top == "{" && ch == "}" || top == "[" && ch == "]"){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        if(s.empty()){
            return true;
        }
        else{
            return false;
        }
    }
}
*/

// ================================= add element in bottom ===============================
/*
// solve function
void solve(stack<int>s, int num){
    // base case
    if(s.empty()){
        s.push(num);
        return;
    }
    int save = s.top();
    s.pop();
    // recursive call
    solve(s, num);
    s.push(save);
    
}
stack<int> addInBottom(stack<int>s, int num){
    solve(s, num);
    return s;
}
*/

// ===================================== reverse the stack ================================
/*
// addInBottom function
void addInBottom(stack<int>& s, int num){
    if(s.empty()){
        s.push(num);
        return;
    }
    int save = s.top();
    s.pop();
    // recursive call to add at bottom.
    addInBottom(s, num);

    s.push(save);
}

// solve function
void solve(stack<int>& s){
    if(s.empty()){
        return;
    }
    int top = s.top();
    s.pop();
    // recursive call
    solve(s);

    // add element in bottom
    addInBottom(s, top);
}

stack<int> reverse(stack<int> s){
    solve(s);
    return s;

}
*/

// ============================== sort the stack ==============================

/*
// sortedInserted function
void sortedInsert(stack<int>&s, int num){
    if(s.empty() || (s.top() < num)){
        s.push(num);
        return;
    }

    int save = s.top();
    s.pop();

    sortedInsert(s, num);

    s.push(save);
}

// solve funciton
void solve(stack<int>&s){
    if(s.empty()){
        return;
    }
    int top = s.top();
    s.pop();
    solve(s);

    sortedInsert(s, top);
}

stack<int> sort(stack<int> s){
    solve(s);
    return s;
}
*/

// ================================== redundent bracket ===============================
/*
bool checkRedundentBracket(stack<char>& s, string str){
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        // push operator and opening bracket in stack.
        if(ch == '+' || ch=='-' || ch=='/' || ch=='*' || ch=='('){
            s.push(ch);
        }
        // if closing bracket then compare.
        else{
            bool redundent = true;
            // loop until we found opening bracket.
            while(s.top() != '('){
                char top = s.top();
                if (top == '+' || top=='-' || top=='/' || top=='*'){
                    redundent = false;
                }
                s.pop();
            }
            s.pop();

            if(redundent == true){
                return true;
            }
        }
    }
    return false;
}
*/

// ==================== Min cost to convert a string in valid parenthesis expression ===================
/*
int MinCost(string str){
    if(str.length()%2 == 1){
        return -1;
    }

    stack<char>s;
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        // if ch is opening bracket then push, if closing then compare from stack's top.
        if(ch == '{'){
            s.push(ch);
        }
        else{
            if(!s.empty() && s.top() == '{'){
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
    }
    // so stack contain invalid parenthesis now.
    int a = 0; 
    int b = 0;
    while(!s.empty()){
        if(s.top() == '{'){
            a++;
        }
        else if(s.top() == '}'){
            b++;
        }
        s.pop();
    }

    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}
*/

// =================================== find next first smaller element ==============================
/*
vector<int> nextSmaller(int arr[], int n){
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    for(int i=n-1; i>=0; i--){
        int a = arr[i];
        while(!s.empty() && s.top() >= a){
            s.pop();
        }
        ans[i] = s.top();
        s.push(a);
    }
    return ans;
}
*/

// =========================== calculate area of maximum rectangle ================================
/*
// function to calculate indexs of next first smaller element.
vector<int> nextSmallerElements(int arr[], int n){
    vector<int>ans(n);
    stack<int>s; 
    s.push(-1);
    for(int i=n-1; i>=0; i--){
        int ch = arr[i];
        while((s.top() != -1) && arr[s.top] >= ch){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

// function to calculate index of prev first smaller elment.
vector<int> prevSmallerElements(int arr[], int n){
    vector<int>ans(n);
    stack<int>s;
    s.push(-1);
    for(int i=0; i<n; i++){
        int ch = arr[i];
        while((s.top()!=-1) && (arr[s.top()] >= ch)){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int calculateMaxArea(vector<int>& heights){
    int n = heights.size();
    // contain first next minimum elements indexes
    vector<int>next(n);
    next = nextSmallerElements(heights, n);

    // contain first prev minimum elements indexes
    vector<int>prev(n);
    prev = prevSmallerElements(heights, n);

    int maxValue = INT_MIN;
    for(int i=0; i<n; i++){
        int length = heights[i];
        if(next[i] == -1){
            next[i] = n;
        }
        int breath = next[i] - prev[i] - 1;

        int area = length * breath;
        maxValue = max(area, maxValue);
    }
    return maxValue;
}
*/

// ================================= Celibrity Problem =============================
/*
// function knows();
bool knows(vector<vector<int>>& M,int a, int b, int n){
    if(M[a][b] == 1){
        return true;
    }
    else{
        return false;
    }
}
int celibrity(vector<vector<int>>& M, int n){
    // step1 : add all elements in stack.
    stack<int>s;
    for(int i=0; i<n; i++){
        s.push(i);
    }

    // step2 : check for upper two elements 
    while(s.size() > 1){
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(knows(M,a,b,n)){
            s.push(b);
        }
        else if(knows(M,b,a,n)){
            s.push(a);
        }
    }

    // if stack is empty.
    if(!s.empty()){ 
        return -1;
    }

    // step 3 : know only one element is left in stack, verify it.

    // check for row.
    bool rowCheck = true;
    int ans = s.top();
    for(int i=0; i<n; i++){
        if(M[ans][i] == 1){
            rowCheck = false;
        }
    }

    // check for col.
    bool colCheck = false;
    int colCount = 0;
    for(int i=0; i<n; i++){
        if(M[i][ans] == 1){
            colCount++;
        }
    }

    if(colCount == n - 1){
        colCheck = true;
    }

    if(rowCheck == true && colCheck == true){
        return ans;
    }
    else{
        return -1;
    }
}
*/

// ========================= max rectanle in binary matrix with all 1's ============================
/*
// function to calculate indexs of next first smaller element.
vector<int> nextSmallerElements(int arr[], int n){
    vector<int>ans(n);
    stack<int>s; 
    s.push(-1);
    for(int i=n-1; i>=0; i--){
        int ch = arr[i];
        while((s.top() != -1) && arr[s.top()] >= ch){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

// function to calculate index of prev first smaller elment.
vector<int> prevSmallerElements(int arr[], int n){
    vector<int>ans(n);
    stack<int>s;
    s.push(-1);
    for(int i=0; i<n; i++){
        int ch = arr[i];
        while((s.top()!=-1) && (arr[s.top()] >= ch)){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

// function calculare max area of rectanle.
int calculateMaxArea(vector<int>& heights){
    int n = heights.size();
    // contain first next minimum elements indexes
    vector<int>next(n);
    next = nextSmallerElements(heights, n);

    // contain first prev minimum elements indexes
    vector<int>prev(n);
    prev = prevSmallerElements(heights, n);

    int maxValue = INT_MIN;
    for(int i=0; i<n; i++){
        int length = heights[i];
        if(next[i] == -1){
            next[i] = n;
        }
        int breadth = next[i] - prev[i] - 1;

        int area = length * breadth;
        maxValue = max(area, maxValue);
    }
    return maxValue;
}

int maxArea(vector<vector<int>> M, int n, int m){
    int area = calculateMaxArea(M[0]);

    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(M[i][j] != 0){
                M[i][j] = M[i-1][j] + M[i][j];
            }
            else{
                M[i][j] = 0;
            }
        }
        int newArea = calculateMaxArea(M[i]);
        area = max(area, newArea);
    }
    return area;
}
*/

