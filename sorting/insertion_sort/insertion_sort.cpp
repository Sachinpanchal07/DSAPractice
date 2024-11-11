#include <iostream>
using namespace std;

void insertion_sort(int arr[], int size){

    for(int i=1; i<size; i++){
        int key = arr[i]; // store the key first
        int j = i - 1;    // store j b/z we have to go from j-1 to j=0.
        
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j]; // shifting the value to the right side.
            j = j-1;   // incriment j.
        }
        arr[j+1] = key; // now insert the key at right place.
        
    }
    for(int i=0; i<size; i++){
        cout<< arr[i] <<endl;
    }
}


int main(){
    int arr[5] = {5,4,1,3,2};
    int size = 5;

    cout << "before sorting: " <<endl;
    for(int i=0; i<size; i++){
        cout<< arr[i] <<endl;
    }

    cout << "after sorting: " << endl;

    insertion_sort(arr, size);

}