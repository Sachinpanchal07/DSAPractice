#include<iostream>
#include<stack>

using namespace std;

// ============================ reverse queue =========================
/*
queue<int> reverse(queue<int> q){
    stack<int> s;
    // build stack
    while(!q.empty()){
        int el = q.front();
        q.pop();
        s.push(el);
    }

    // build queue
    while (!s.empty())
    {
        int el = s.top();
        s.pop();
        q.push(el);
    }
    return q;
    
}
*/

// =============================== reverse k elements of queue =============================
queue<int> reverse(queue<int>q, int k){
    stack<int>s;
    for(int i=0; i<k; i++){
        int el = q.front();
        q.pop();
        s.push(el);
    }

    while(!s.empty()){
        int el = s.top();
        s.pop();
        q.push(el);
    }

    int t = q.size()-k;
    while(t--){
        int el = q.front();
        q.pop();
        q.push(el);
    }
    return q;
}
int main(){

}