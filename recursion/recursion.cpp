#include <iostream>
using namespace std;

// factorial of n

/*
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
*/

// counting of 1 to n;

/*
void count(int n){
    // base case
    if(n==0){
        return;
    }
    cout << n << endl;// processing
    count(n-1); // recursive relation
    cout << n << endl;
}

int main(){
    int n = 10;
    count(n);
    return 0;
}
*/

// fibonacci series
/*
int fib(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    int ans = fib(n-1) + fib(n-2);
    return ans;
}

int main(){
    int n = 8;
    int ans = fib(n);
    cout << ans ;
}
*/

// Say digit
void printDigit(int n, string arr[]){
    if(n == 0){
        return;
    }
    int digit = n%10;
    n = n / 10;
    printDigit(n, arr);
    cout << arr[digit] << " ";
}

int main()
{
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n = 3435;
    printDigit(n, arr);
}
