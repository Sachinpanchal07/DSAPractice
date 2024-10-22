// #include <iostream>
// using namespace std;
// int main(){
//     int arr[5] = {4,7,3,9,0};
//     for(int i=0; i<4; i++){
//         int index = i;
//         for(int j=i+1; j<5; j++){
//             if(arr[j] <= arr[index]){
//                 index = j;
//             }
//         }
//         swap(arr[index], arr[i]);
//     }

//     // print sorted array.
//     for(int i=0; i<5; i++){
//         cout << arr[i] << endl;
//     }
// }

#include <iostream>
using namespace std;
void selectionSort(int arr[], int size){
int min;
    for(int i=0; i<size-1; i++){
        min = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] <= arr[min]){
                min = j;
            }
        }
        swap(arr[min], arr[i]);

    }
    cout << "now sorted arry will be printed:"<<endl;
    for(int i=0; i<size; i++){
        cout << arr[i]<< endl;
    }
}


int main(){
    int arr[5] = {3,5,7,1,7};
    int size = 5;
    for(int i=0; i<size; i++){
        cout << arr[i]<< endl;
    }
    selectionSort(arr, size);
}