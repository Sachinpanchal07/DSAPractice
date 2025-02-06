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
int main(){

}