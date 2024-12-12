#include<iostream>
#include<vector>
using namespace std;


// merge sort
void merge(int* arr, int s, int mid, int e){
    int l1 = mid-s+1;
    int l2 = e-mid;

    // create new arrays dynamcilly
    int* left = new int[l1];
    int* right = new int[l2];
    
    // copy elements
    int k = s;
    for(int i=0; i<l1; i++){
        left[i] = arr[k++];
    }
    k = mid+1;
    for(int i=0; i<l2; i++){
        right[i] = arr[k++];
    }

    // merge two sorted array.
    int index1 = 0;
    int index2 = 0;
    k = s;
    while(index1 < l1 && index2 < l2){
        if(left[index1] < right[index2]){
            arr[k++] = left[index1++];
        }
        else{
            arr[k++] = right[index2++];
        }
    }
    // if any of one array is finished
    while(index1<l1){
        arr[k++] = left[index1++];
    }
    while(index2<l2){
        arr[k++] = right[index2++];
    }

}

void mergeSort(int *arr, int s, int e){
    if(s>=e){
        return;        
    }
    int mid = s+(e-s)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    merge(arr, s, mid, e);
}

int main(){
    int arr[8] = {4,8,5,3,6,9,5,2};
    int len = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, len-1);

    for (int i=0; i<len-1; i++){
        cout << arr[i] << " ";
    }
}