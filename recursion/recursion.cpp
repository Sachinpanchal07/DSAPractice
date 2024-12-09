#include <iostream>
using namespace std;

// =========================factorial of n

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

// =================counting of 1 to n;

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

// ======================fibonacci series

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

// =============================Say digit

/* void printDigit(int n, string arr[]){
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
*/

// =======================Is array sorted

/*
bool isSorted(int *arr, int size){
    if(size == 0 || size == 1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    else{
    bool ans = isSorted(arr+1, size-1);
    return ans;
    }
}

int main(){
    int arr[6] = {1,2,3,4,5,6};
    int size = 6;
    bool ans;
     
    ans = isSorted(arr, size); 
    if(ans==true){
        cout << "array is sorted";
    }
    else{
        cout << "Not sorted";
    }
}
*/

// ==========================sum of array

/*
int sum(int* arr, int size){
    if(size == 0 ){
        return 0;
    }
    int ans = arr[0] + sum(arr+1, size-1);
    return ans;
}

int main(){
    int arr[6] = {5,2,3,4,5,6};
    int size = 6;
    int ans;
     
    ans = sum(arr, size); 
    cout << "sum of elements is " <<  ans;
}
*/

// =============================linear search
/*
bool find(int* arr, int size, int key){
    if(size == 0){
        return false;
    }
    else{
        if(arr[0] == key){
            return true;
        }

        return find(arr+1, size-1, key);
    }
    
}

int main(){
    int arr[6] = {5,2,3,4,5,6};
    int size = 6;
    int key = 5;
    bool ans;
     
    ans = find(arr, size, key); 
    if(ans){
        cout<< "element found ";
    }
    else{
        cout << "not found";
    }
}
*/

// =============== binary search
/*
bool find(int* arr, int key, int s, int e){
    if(s > e){
        return false;
    }
    int mid = (s+e)/2;

    if(key == arr[mid]){
        return true;
    }
    else if(key > arr[mid]){
        
       return find(arr, key, mid+1, e);
    }
    else{
       return find(arr, key, s, mid-1);
    }
}

int main(){
    int arr[6] = {1,2,3,4,5,6};
    int size = 6;
    int key = 6;
    int s = 0;
    int e = size-1;

    bool ans;
     
    ans = find(arr, key, s, e); 
    if(ans){
        cout<< "element found ";
    }
    else{
        cout << "not found";
    }
}
*/

// reverse string

/*
void reverse(string& str, int s, int e){
    if(s>e){
        return;
    }
    swap(str[s], str[e]);
    s++;
    e--;
    reverse(str, s, e);
}

int main(){
   string str = "abcde";
   int s = 0;
   int e = str.length()-1;
   reverse(str, s, e);
   for(int i=0; i<str.length(); i++){
    cout << str[i];
   }
}
*/

// check palindrome

/*
bool reverse(string str, int s, int e){
    if(s>e){
        return true;
    }
    if(str[s] != str[e]){
        return false;
    }
    s++;
    e--;
    return reverse(str, s, e);
    
}

int main(){
    string str = "abcba";
    cout << reverse(str, 0, str.length()-1);
}
*/