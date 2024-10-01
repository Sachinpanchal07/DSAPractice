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
int binarySearch(int arr[], int size, int key, int s, int e)
{
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

// find pivot
int getPivot(int arr[], int size, int key)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] > arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
  
    return s;
}

// function for execution
int getElement(int arr[], int size, int key)
{
    int pivot = getPivot(arr, size, key);
    if (arr[pivot] <= key && key <= arr[size - 1])
    {
        return binarySearch(arr, size, key, pivot, size - 1); // go to 2nd sorted part.
    }
    else
    {
        return binarySearch(arr, size, key, 0, pivot - 1); // else go to 1st sorted part.
    }
}

int main()
{
    int arr[7] = {13, 17, 19, 1, 5, 8, 9};
    int size = 7;
    int key = 17;
    int result = getElement(arr, size, key);
    if(result != -1){
        cout << "The element is present at index of: " << result;
    }
    else{
        cout << "Element is not present in array.";
    }
}