#include<iostream>
#include<vector>
using namespace std;


// merge two sorted arrays

vector<int> merge(vector<int>& arr1, vector<int>& arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i=0, j=0;
    vector<int> arr3;

    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j]){
            arr3.push_back(arr1[i]);
            i++;
        }
        else{
            arr3.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n1){
        arr3.push_back(arr1[i]);
        i++;
    }
    while (j<n2)
    {
        arr3.push_back(arr2[j]);
        j++;
    }
    return arr3;
}

int main(){
    vector<int> arr1 = {2,4,6,8,10};
    vector<int> arr2 = {1,3,5,7,9};

    vector<int> ans = merge(arr1, arr2);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
}