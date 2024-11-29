#include<iostream>
using namespace std;

int main(){
    
    int num = 5;
    int *ptr = &num;

    // cout << ptr << endl;
    // cout << *ptr << endl;
    // cout << sizeof(ptr) << endl;
    // cout << sizeof(*ptr) << endl;

    int *q = ptr;
    cout << *q;
}