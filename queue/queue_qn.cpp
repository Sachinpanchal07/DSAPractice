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
/*
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
*/
// ============================ first non-repeating character in stream ===================
/*
vector<int> repear(string s){
    map<char, int>m;
    queue<char>q;
    vector<char>v;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        m[ch]++;
        q.push(ch);
        while(!q.empty()){
            if(m[q.front()] > 1){ // if frequency greater 1 pop.
                q.pop();
            }
            else{
                v.push_back(q.front());
                break;
            }
        }
        if(!q.empty()){
            v.push_back('#');
        }
    }
    return v;
}
*/

// ================================== petrol pump question ====================================
/*
// d = distance, p = petro.
int circularTour(vector<int>p, vector<int>d){
    int start = 0;
    int balance = 0;
    int defficiency = 0;
    for(int i=0; i<p.size(); i++){
        balance += p[i] - d[i];
        if(balance < 0){
            defficiency += balance;
            start = i + 1;
            balance = 0;
        }
    }
    if(balance + defficiency >= 0){
        return start;
    }
    else{
        return -1;
    }
}
*/
int main(){

}