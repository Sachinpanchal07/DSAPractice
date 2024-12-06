#include<iostream>
using namespace std;

// rotate array ....
/*
void rotate(int nums[], int k, int size){

    k = k%size; // must include this line.
            int s = 0;
            int e = size-1;
            while(s<=e){
                swap(nums[s], nums[e]);
                s++;
                e--;
            }
            s = 0; 
            e = k-1;
            while(s<=e){
                swap(nums[s], nums[e]);
                s++;
                e--;
            }

            s = k;
            e = size - 1;
            while(s<=e){
                swap(nums[s], nums[e]);
                s++;
                e--;
            }
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int n = 2;
    int size = 5;
    rotate(arr,n,size);

    for(int i=0; i<size; i++){
        cout << arr[i] << endl;
    }
}
*/

// square of sorted array
/*
void sq(int *arr,int n){
    // sq the array;
    for(int i=0; i<n; i++){
        arr[i] = arr[i]*arr[i];
    }

    // sort the array.
    for(int i=0; i<n-1; i++){
        int index = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[index]){
                index = j;
            }
        }
        swap(arr[i],arr[index]);
    }
    for(int i=0; i<n; i++){
        cout << arr[i] << endl;
    }
}

int main(){
    int arr[] = {-4,-1,0,3,10};
    int n = 5;
    sq(arr,n);
}
*/