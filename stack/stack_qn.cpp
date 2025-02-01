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


int main(){
   
}