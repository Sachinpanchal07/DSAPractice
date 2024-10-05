#include <iostream>
using namespace std;

// +++++++++++++++ First and last occurence of the element in array otherwise return -1 +++++++++++++++++++++++++++++++++++
// easy level
// int first_occ(int arr[], int size, int key){
//     int s = 0;
//     int e = size-1;
//     int mid = (s+e)/2;
//     int ans = -1;

//     while (s<=e)
//     {
//         if(key == arr[mid])
//         {
//             ans = mid;
//             e = mid - 1;
//         }
//         else if(key < arr[mid])
//         {
//             e = mid - 1;
//         }
//         else{
//             s = mid + 1;
//         }
//         mid = (s+e)/2;
//     }
//     return ans;
// }

// int last_occ(int arr[], int size, int key){
//     int s = 0;
//     int e = size-1;
//     int mid = (s+e)/2;
//     int ans = -1;

//     while (s<=e)
//     {
//         if(key == arr[mid])
//         {
//             ans = mid;
//             s = mid + 1;
//         }
//         else if(key > arr[mid])
//         {
//             s = mid + 1;
//         }
//         else{
//             e = mid - 1;
//         }
//         mid = (s+e)/2;
//     }
//     return ans;
// }

// int main(){
//     int arr[7] = {1,3,5,5,5,6,7};
//     int size = 7;
//     int key = 3;
//     cout << "first occurence of the element at index of: " << first_occ(arr, size, key) << endl;
//     cout << "last occurence of the element at index of: " << last_occ(arr, size, key);
// }

// ++++++++++++++++++++++++++++++ Peak index in a mountain array +++++++++++++++++++++++++++++

// int peak_index(int arr[], int size){
//     int s = 0;
//     int e = size - 1;
//     int mid = (s + e)/2;

//     while(s<e){
//         if(arr[mid] < arr[mid + 1]){
//             s = mid + 1;
//         }
//         else {
//             e = mid;
//         }
//         mid = (s + e)/2;
//     }
//     return s;

// }

// int main(){
//     int arr[5] = {1,3,9,8,7};
//     int size = 5;
//     cout << "peak value in the index is: " <<  peak_index(arr, size);
// }

// +++++++++++++++++++++++++++++++ Find the Pivot (min or max value in rotated sorted array) +++++++++++

// int pivot(int arr[], int size ){
//     int s = 0;
//     int e = size - 1;
//     int mid = s + (e-s)/2;

//     while(s<e){
//         if(arr[mid] > arr[0]){
//             s = mid + 1;
//         }
//         else{
//             e = mid;
//         }
//         mid = s + (e-s)/2;
//     }
//     return s;
// }

// int main(){
//     int arr[6] = {13,17,21,2,5,7};
//     int size = 5;
//     cout << "Pivot is at the index of: " << pivot(arr, size);
// }

// ++++++++++++++++++++++++++++++ find element in sorted rotated array ++++++++++++++++++++++++++++++++++

// find element
// int binarySearch(int arr[], int size, int key, int s, int e)
// {
//     int mid = s + (e - s) / 2;
//     while (s <= e)
//     {
//         if (key == arr[mid])
//         {
//             return mid;
//         }
//         else if (key < arr[mid])
//         {
//             e = mid - 1;
//         }
//         else
//         {
//             s = mid + 1;
//         }
//         mid = s + (e - s) / 2;
//     }
//     return -1;
// }

// // find pivot
// int getPivot(int arr[], int size, int key)
// {
//     int s = 0;
//     int e = size - 1;
//     int mid = s + (e - s) / 2;

//     while (s < e)
//     {
//         if (arr[mid] > arr[0])
//         {
//             s = mid + 1;
//         }
//         else
//         {
//             e = mid;
//         }
//         mid = s + (e - s) / 2;
//     }
  
//     return s;
// }

// // function for execution
// int getElement(int arr[], int size, int key)
// {
//     int pivot = getPivot(arr, size, key);
//     if (arr[pivot] <= key && key <= arr[size - 1])
//     {
//         return binarySearch(arr, size, key, pivot, size - 1); // go to 2nd sorted part.
//     }
//     else
//     {
//         return binarySearch(arr, size, key, 0, pivot - 1); // else go to 1st sorted part.
//     }
// }

// int main()
// {
//     int arr[7] = {13, 17, 19, 1, 5, 8, 9};
//     int size = 7;
//     int key = 17;
//     int result = getElement(arr, size, key);
//     if(result != -1){
//         cout << "The element is present at index of: " << result;
//     }
//     else{
//         cout << "Element is not present in array.";
//     }
// }

// +++++++++++++++++++++++++++++++++ sqrt using binary search ++++++++++++++++++++++++++++++++++++++

// long long int binarySerach(int n){
//     int s = 0;
//     int e = n;
//     long long int mid = s + (e-s)/2;
//     long long int ans = 0;
//     while(s <= e){
//         long long int sq = mid * mid;
//         if(sq == n){
//             return mid;
//         }
//         else if(sq < n){
//             ans = mid;
//             s = mid + 1;
//         }
//         else{
//             e = mid - 1;
//         }
//         mid = s + (e-s)/2;
//     } 
//     return ans;
// }

// int main(){
//     int num = 36;
//     cout << "The int sqrt of the number is :" << binarySerach(35);
// }

//  ++++++++++++++++++++++++++++++++++++ search insert position +++++++++++++++++++++++++++++++++

// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the      index where it would be if it were inserted in order.

// int getElement(int arr[], int size, int key){
//     int s = 0;
//     int e = size - 1;
//     int mid = s + (e-s)/2;

//     while(s<=e){
//         if (arr[mid] == key){
//             return mid;
//         }
//         else if (key < arr[mid]){
//             e = mid - 1;
//         }
//         else{
//             s = mid + 1;
//         }
//         mid = s + (e-s)/2;
//     }
//     return -1;
// }

// int getIndex(int arr[], int size, int key){
//     int s = 0;
//     int e = size - 1;
//     int mid = s + (e-s)/2;
//     while(s<=e){
//         if(key < arr[mid]){
//             e = mid - 1;
//         }
//         else{
//             s = mid + 1;
//         }
//         mid = s + (e-s)/2;
//     }
//     return s;
// }

// int main(){
//     int arr[4] = {1,3,5,6};
//     int size = 4;
//     int key = 2;
//     int result = getElement(arr, size, key);

//     if (result == -1){
//         cout << "The element should be present at the index of: " << getIndex(arr, size, key);
//     }
//     else{
//         cout << "The element is present at the index of: " << result;
//     }

// }

// +++++++++++++++++++++++++++++finding missing element+++++++++++++++++++++++

int findElement(int arr[],int size){
    int el_sum = 0;
    int arr_sum = 0;
    for(int i= 0; i<=size; i++){
        el_sum += i;
    }
    for(int i= 0; i<size; i++){
        arr_sum += arr[i];
    }

    return (el_sum - arr_sum);

}


int main(){
    int arr[9] = {9,6,4,2,3,5,7,0,1};
    int size = 9;
    cout << "The missing number is: " << findElement(arr, size);
// }

