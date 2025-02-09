#include<iostream>
#include<stack>
#include<vector>
#include<queue>

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

// =====================  Find the First Negative Integer in Every Window of Size K =================== 
/*
vector<int> firstNegativeWindow(int arr[], int k){
    vector<int> ans;
    queue<int>q;
    int len = arr.sizeof()/arr[0].sizeof();
    int i=0; 
    int j=0;
    while(j<len){
        // element is -ve push in q
        if(arr[j] < 0){
            q.push(arr[j]);
        }
        // checking if window size reah.
        if(j-i+1 == k){
            if(!q.empty()){
                ans.push_back(q.front());
            }else{
                ans.push_back(0);
            }
            if(arr[i] < 0 && !q.empty()){
                q.pop();
            }
            i++;
        }
        j++;
    }
    return ans;
}
*/



// this is wrong dont consider this...........................................
/*
vector<int> sumOfMaxMin(int arr[], int k, int n){
    vector<int>ans;
    queue<int>max_q;
    queue<int>min_q;
    int i; 
    max_q.push(arr[0]);
    min_q.push(arr[0]);
    int j;
    while (j<n)
    {
        // min queue.
        if(arr[j] < min_q.front()){
            min_q.pop();
            min_q.push(arr[j]);

        }
        // max queue.
        if(arr[j] > max_q.front()){
            max_q.pop();
            max_q.push(arr[j]);
        }

        if(j-i+1 == k){
            int sum;
            if(!min_q.empty() && !max_q.empty()){
                sum = max_q.front() + min_q.front();
                ans.push_back(sum);
            }
            if(max_q.front() == arr[i]){
                max_q.pop();
            }
            if(min_q.front() == arr[i]){
                min_q.pop();
            }
            i++;
        }
        j++;
    }
    return ans;
}
*/
int main(){

}