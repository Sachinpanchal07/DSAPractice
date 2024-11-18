#include<iostream>
using namespace std;

//============================ char arrays ================================== 

// ================== check palindrome =========================
int main(){
    char a[5] = {'a','b','c','b','a'};
    int s = 0;
    int e = 4;
    bool pal = true;
    while(s<e){
        if(a[s]!=a[e]){
            pal = false;
            break;
        }
        s++;
        e--;
    }
    if(pal == true){
        cout << "palindrome";
    }else{
        cout << "not palindrome";
    }
}