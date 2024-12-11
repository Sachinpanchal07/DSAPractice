#include<iostream>
#include<vector>
using namespace std;

// merge both left and right array.
void merge(int *arr, int s, int mid, int e){
    int l1 = mid-s+1; // length of first half
    int l2 = e-mid;   // length of second half array

    // create two new arrays 
    int* first = new int[l1];
    int* second = new int[l2];

    // copy the first half of main array into new array
    int k = s; // s is the main array index , we dont want to change s, so we take a variabe equal to s.
    for(int i=0; i<l1; i++){
        first[i] = arr[k];
        k++;
    }

    // opy the first half of main array into new array
    k = mid + 1;
    for(int i=0; i<l2; i++){
        second[i] = arr[k];
        k++;
    }

    // code for merge two sorted array into main array.
    int index1 = 0;
    int index2 = 0;
    k = s;
    while(index1 < l1 && index2 < l2){
        if(first[index1] < second[index2]){
            arr[k] = first[index1];
            k++;
            index1++;
        }
        else{
            arr[k] = second[index2];
            k++;
            index2++;
        }
    }
    // if any of array has finished 
    while(index1 < l1){
        arr[k] = first[index1];
        k++;
        index1++;
    }
    
    while(index2<l2){
        arr[k] = second[index2];
        k++;
        index2++;
    }
    delete [] first; // free up the memory of heap
    delete [] second;
}


// mergeSort
void mergeSort(int *arr, int s, int e){
    if(s>=e){
        return;
    }
    int mid = s+(e-s)/2;
    // sort left part
    mergeSort(arr, s, mid);
    // sort right part
    mergeSort(arr, mid+1, e);

    // merge both sorted array.
    merge(arr, s, mid, e);
}

int main(){
    int arr[9] = {3,5,7,78,5,4,3,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}