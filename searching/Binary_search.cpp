#include <iostream>
using namespace std;

int binary_search(int arr[], int size, int key){
    
    int start = 0;
    int end = 5;
    int mid = (start + (end-start)/2); // for optimization of code for test cases.

    while(start<=end){
        if(arr[mid] == key){
            return mid;
        }
        else if(key < arr[mid]){
            end = mid-1;    // menas key is present left side of the mid element.
        }
        else{
            start = mid + 1; // means key is present right side of the mid element.
        }
        mid = (start + (end-start)/2);
    }
    return -1;
}

int main(){
    int arr[6] = {2,4,6,8,11,12};
    int key = 12;
    int ans = binary_search(arr,6,key);
    cout << "element present at index of : " << ans;

}