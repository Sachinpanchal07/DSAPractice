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

// solve funtion
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

int main(){
   
}