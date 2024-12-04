#include<iostream>
using namespace std;

// factorial of n
int factorial(int n){
    // base case 
    if(n==0){
        return 1;
    }
    // recursive case
    return n * factorial(n-1);
}

int main(){
    int n = 5;
    int ans = factorial(n);
    cout << ans;
    return 0;
}

