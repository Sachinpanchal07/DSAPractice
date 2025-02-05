#include<iostream>
using namespace std;
class Circular_queue{
    public:
    int size;
    int front;
    int rear;
    int *arr;

    Circular_queue(){
        size = 10000;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    // push operation

    void push(int el){
        if(rear == size-1 && front == 0 || rear == front-1 % size-1){
            cout << "queue is full, can't add";
        }
        // if queue is empty.
        else if(front == -1){
            front = 0;
            rear = 0;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = el;
    }

    // pop operation

    int pop(){
        if(front == -1){
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear){
            front = rear = -1;
        }
        if(front == size-1){
            front = 0;
        }
        else {
            front++;
        }
        return ans;
    }
};

int main(){
    Circular_queue queue;
    queue.push(5);
    queue.push(10);
    queue.push(15);
    queue.push(20);

    queue.pop();
}