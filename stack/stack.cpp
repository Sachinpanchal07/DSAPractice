#include<iostream>
// #include<stack>
using namespace std;

// ================================ stact implementation using classess ===========================
class Stack{
    private:
    int *arr;
    int capacity;
    int top;

    public:
    Stack(int size){
        capacity = size;
        top = -1;
        arr = new int[size];
    }

    // behavious 
    void push(int data){
        if(top == capacity-1){
            cout << "stack overflow ";
            return;
        }
        else{
            top++;
            arr[top] = data;
        }
    }

    int pop(){
        if(top == -1){
            cout << "stack underflow ";
        }
        else{
            int ele = arr[top];
            top--;
            return ele;
        }
    }

    int peek(){
        if(top == -1){
            cout << "stack underflow ";
            return -1;
        }
        else{
            int ele = arr[top];
            return ele;
        }
    }

    bool empty(){
        if(top == -1){
            return true;
        }
        return false;
    }

    int size(){
        if(top == -1){
            return 0;
        }
        else{
            int ele = top+1;
            return ele;
        }
    }
};

int main(){

    Stack s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    
    cout << "deleting last element of stack, " << s.pop() << " is deleted " << endl;
    s.push(4);

    // stack elements
    while(!s.empty()){
        cout << s.peek() << endl;
        s.pop();
    }
    
    // cout << "top element is " << s.peek() << endl;
    // cout << "size of stack is " << s.size() << endl;
    // cout << "stack is emepty or not--> " << s.empty() << endl;


    // ========= using STL =========
    
    /*
    stack<int> s;
    s.push(1);
    while(!s.empty()){
        int a = s.top();
        s.pop();
        cout << a << endl;
    }
    */
}