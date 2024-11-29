#include<iostream>
#include<vector>
using namespace std;

// ================================ sieve of eratosthenes =========================================
// this is optimize solution for finding prime numbers less then a given number.

// int main(){
//     int n = 40;
//     int count = 0;
//     vector<bool> isPrime(n+1, true);

//     // mark 0,1 false manually
//     isPrime[0] = isPrime[1] = 0;
    
//     // loop from 2 to 40
//     for(int i=2; i<n; i++){
//         // if number is true, count++
//         if(isPrime[i]){
//             count++;
//             // mark multiples of number false
//             for(int j=i*i; j<n; j=j+i){
//                 isPrime[j] = false;
//             }
//         }
//     }
//     cout << "number of prime numbers less than "<< n << " is " << count;
// }

// =================================== finding GDC/HCF =====================================

// int main(){

//     int a = 68, b = 22;

//     if(a==0){
//         cout << b;
//     }
//     if(b==0){
//         cout << a;
//     }
//     while(a!=b){
//         if(a>b){
//             a = a-b;
//         }
//         else{
//             b = b-a;
//         }
//     }
//     cout << a;
// }

// 