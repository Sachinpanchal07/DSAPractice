#include<iostream>
using namespace std;

// int main(){
    
    // int num = 5;
    // int *ptr = &num;

    // cout << ptr << endl;
    // cout << *ptr << endl;
    // cout << sizeof(ptr) << endl;
    // cout << sizeof(*ptr) << endl;

    // int *q = ptr;
    // cout << *q;

    // ======================== pointer with int array ========================

    // int arr[10] = {2,5,6,4};
    // cout << arr << endl; // address
    // cout << *arr << endl; // 2
    // cout << *(arr+1) << endl; // 5 
    // cout << *(arr) + 1 << endl; // 3
    // int i = 3;
    // cout << i[arr] << endl; // 4 

    // ========================= double pointers =============================
    // int i = 5;
    // int* ptr = &i;
    // int** ptr2 = &ptr;

    // cout << ptr << endl; // print address of i
    // cout << ptr2 << endl; // address of p
    // cout << *ptr2 << endl; // print address of i
    // cout << **ptr2<< endl; // print value of i
    // cout << " ======== address of i is:  " << endl;
    // cout << &i << endl;
    // cout << ptr << endl;
    // cout << *ptr2 << endl;
// }

// ====================== functions with double pointers ================ 

// void update(int* p, int** p2){
//     p += 1;
//     p2 += 1;
//     *p2 += 1;
//     **p2 += 1;
// }

// int main(){
//     int i = 5;
//     int* p = &i;
//     int** p2 = &p;
//     cout << "before " << endl;
//     cout << i << endl;
//     cout << p << endl;
//     cout << p2 << endl;
//     update(p,p2);

//     cout << "after" << endl;
//     cout << i << endl;
//     cout << p << endl;
//     cout << p2 << endl;
// }