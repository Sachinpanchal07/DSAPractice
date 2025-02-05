#include<iostream>
#include<deque>   
using namespace std;

class Deque{
    public:
    int size;
    int front;
    int rear;
    int *arr;

    Deque(){
        size = 10000;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

// push from front.
    void push_front(int el){
        if(front == 0 && rear == size-1 || rear == front-1 % size-1){
            cout << "queue is full" << endl;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else if(front == 0){ // for cyclic nature
            front = size - 1;
        }
        else{
            front--;
        }
        arr[front] = el;
    }

// push from back (same as circular queue)

    void push_back(int el){
        if((front == 0) && (rear == size-1) || (rear == front-1) % (size-1)){
            cout << "queus is full";
        }
        // if queue is empty.
        else if(front == -1){
            front = 0;
            rear = 0;
        }
        else if(rear == size-1 && front != 0){
            rear = 0; // for cyclic nature
        }
        else{
            rear++;
        }
        arr[rear] = el;
    }

    // pop from rear.

    int pop_rear(){
        if(rear == -1){ // empty case
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;

        if(front == rear){ // single element is present
            front = -1; 
            rear = -1;
        }
        else if(rear == 0){ // rear at zero index(to maintian cyclic nature)
            rear = size-1;
        }
        else{
            rear--;
        }
        return ans;
    }

    // pop from front 

    int pop_front(){
        if(front == -1){
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear){
            front = -1;
            rear = -1;
        }
        if(front == size-1){
            front = 0;
        }
        else {
            front++;
        }
        return ans;
    }

    // is empty.
    bool isEmpty(){
         return front == -1;
    }
};



int main(){
    Deque q;
    q.push_front(1);
    cout << q.isEmpty() <<endl;
    q.push_back(2);
    q.push_back(3);
    q.pop_front();
    q.pop_rear();
    q.pop_rear();
    cout << q.isEmpty() << endl;


    //  Deque implementation using STL.
    /*
    deque<int>q;
    q.push_front(1);
    q.push_back(2);
    cout << q.front() << endl;
    cout << q.empty() << endl;
    q.pop_front();
    cout << q.front() << endl;
    */
}