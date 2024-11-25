#include <iostream>
using namespace std;
void bubbleSort(int arr[], int size){
    for (int i=1; i<size; i++){
        bool sorted = false;
        for(int j=0; j<size-i; j++){ // size-i, b/z in each round last element  is sorted, and we don't need to see that element again.
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                sorted = true;
            }
            if (sorted==true){ // more optimized
                break; // Means array is already sorted b/z no swaping occured.
            }
        }
    }
    for(int i=0; i<size; i++){
        cout << arr[i] << endl;
    }
}
int main(){
    int arr[5] = {5,4,3,2,1};
    int size = 5;
    cout << "before sorting:" << endl;
    for(int i=0;i<size;i++){
        cout << arr[i] << endl;
    }
    cout << "after Sorting: "<<endl;
    bubbleSort(arr, size);
}