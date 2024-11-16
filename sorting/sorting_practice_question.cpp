#include <iostream>
#include <vector>
using namespace std;


// ++++++++++++++++++++++ reverse array +++++++++++++++++++++++++++++

// void reverse(int arr[], int size){
//     int s = 0;
//     int e = size-1;

//     while (s < e){
//         swap(arr[s], arr[e]);
//         s += 1;
//         e -= 1;
//     }

//     cout << "after the reverse" << endl;

//     for(int i = 0; i < size ; i++){
//         cout << arr[i] << endl;
//     }
// }
// int main(){
// int arr[5] = {4,6,3,5,8};
// int size = 5;
// reverse(arr, size);

// }

// ======================= reverse vector =====================================

// vector<int> reverse(vector<int> v){
//     int s = 0, e = v.size() - 1;
//     while(s <= e){
//         swap(v[s], v[e]);
//         s++;
//         e--;
//     }

//     return v;

// }
// void print(vector<int> v){
//     for(int i = 0; i< v.size(); i++){
//         cout << v[i] << " ";
//     }
// cout << endl;
// }

// int main(){

//     vector<int> v;

//     v.push_back(11);
//     v.push_back(7);
//     v.push_back(3);
//     v.push_back(12);
//     v.push_back(4);

//     vector<int> ans = reverse(v);
//     print(ans);

//     return 0;
// }

// ===================== merge two sorted array ===================================

// void merge(int a[], int size1, int b[], int size2, int c[]){
//     int i=0,j=0,k = 0;
//     while( i < size1 && j < size2){
//         if(a[i] < b[j]){
//             c[k++] = a[i++];
//         }
//         else{
//             c[k++] = b[j++];
//         }
//     }

//     while(i < size1){
//         c[k++] = a[i++];
//     }
//     while(j < size2){
//         c[k++] = b[j++];
//     }

//     for(int i=0; i<8; i++){
//         cout << c[i] << endl;
//     }
// }


// int main(){
//     int a[5] = {1,3,5,7,9};
//     int b[3] = {2,4,6};
//     int c[8];

//     merge(a, 5, b, 3, c);
// }

// ===================================================

// int main(){
//     int a[5] = {1,0,5,0,9};
//     int s = 0;
//     int e = 4;
//     while(s < e){
//         if(a[s] == 0 || a[e] == 0){
//             swap(a[s], a[e]);
//             s++;
//             e--;
//         }
//     }
//     for(int i=0; i<4; i++){
//         cout << a[i]<< " ";
//     }
// }


// ============================ putting zero's value at right side ============================
// int main(){
//     int arr[8] = {2,0,1,0,3,0,0,0};
//     int size = 8;
//     for(int i=1; i<size; i++){
//         int key = arr[i];
//         int j = i-1;
//         while(j>=0 && arr[j]==0){
//             arr[j+1] = arr[j];
//             j -= 1;
//         }
//         arr[j+1] = key;
//     }
//     cout << "after sorting: " << endl;
//     for(int i=0; i<size; i++){
//         cout << arr[i] << endl;
//     }
// }
// =========================== alternate of upper code ======================================
int main(){
    int arr[5] = {3,0,5,0,0};
    int size = 5;
    int nonZero = 0;
    for(int j=0; j<size; j++){
        if(arr[j] != 0){
            swap(arr[nonZero], arr[j]);
            nonZero++; 
        }
    }
    for(int i=0; i<size; i++){
        cout << arr[i]<< endl;
    }
}