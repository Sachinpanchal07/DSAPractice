#include<iostream>
using namespace std;

// This func arranges that left part is lower then pivot and right part is higher then pivot  and returns pivot index.
int partitaion(int* arr, int s, int e){
    int pivot = arr[s];
    int i = s;
    int j = e;

    while(i < j){
        while(arr[i]<=pivot && i<e){
            i++;
        }
        while(arr[j]>pivot && j>s){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[s]);

    return j;
}

void quickSort(int *arr, int s, int e){
    if(s<e){
        int pivotIndex = partitaion(arr, s, e); 

        // for left part
        quickSort(arr, s, pivotIndex-1);
        // for right part
        quickSort(arr, pivotIndex+1, e);
    }
}

int main(){
    int arr[8] = {9,23,5,2,2,4,9,8};
    int size = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, size-1);

    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}