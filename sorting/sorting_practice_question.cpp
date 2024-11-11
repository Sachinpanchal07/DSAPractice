#include <iostream>
#include <vector>
using namespace std;


// ++++++++++++++++++++++ reverse array +++++++++++++++++++++++++++++

// void reverse(int arr[], int size){
//     int s = 0;
//     int e = size-1;

//     while (s < e){
//         swap(arr[s], arr[e]);
//         s += 1;
//         e -= 1;
//     }

//     cout << "after the reverse" << endl;

//     for(int i = 0; i < size ; i++){
//         cout << arr[i] << endl;
//     }
// }
// int main(){
// int arr[5] = {4,6,3,5,8};
// int size = 5;
// reverse(arr, size);

// }

// ======================= reverse vector =====================================

vector<int> reverse(vector<int> v){
    int s = 0, e = v.size() - 1;
    while(s <= e){
        swap(v[s], v[e]);
        s++;
        e--;
    }

    return v;

}
void print(vector<int> v){
    for(int i = 0; i< v.size(); i++){
        cout << v[i] << " ";
    }
cout << endl;
}

int main(){

    vector<int> v;

    v.push_back(11);
    v.push_back(7);
    v.push_back(3);
    v.push_back(12);
    v.push_back(4);

    vector<int> ans = reverse(v);
    print(ans);

    return 0;
}