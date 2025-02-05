#include<iostream>
#include<queue>
using namespace std;

class Queue {
    public:
    int size;
    int front; 
    int rear;
    int* arr;
    Queue(){
        size = 10000;
        front = 0; 
        rear = 0;
        arr = new int[size];
    }

    bool empty(){
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    void push(int el){
        if(rear == size){
            cout << "can't add, queue is full " << endl;
        }
        else{
            arr[rear++] = el;
        }
    }

    int pop(){
        if(front == rear){
            return -1;
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0; 
                rear = 0;
            }
            return ans;
        }
    }
    int front_el(){
        if(front == rear){
            return -1;
        }
        else{
            return arr[front];
        }
    }
};

int main(){
    Queue queue;
    queue.push(5);
    queue.push(10);
    queue.push(15);
    queue.pop();
    cout << queue.front_el() << endl;
    cout << queue.empty() << endl;


    // ========================= queue using STL =============================
    /*
    queue<int>q;
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.size() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << q.empty() << endl;
    */
}