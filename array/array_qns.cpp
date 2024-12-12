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

/*
class Solution {
public:
    bool isPalindrome(int x) {
        // string str = to_string(x);
        // int s = 0;
        // int e = str.length() - 1;
        // while (s <= e) {
        //     if (str[s++] != str[e--]) {
        //         return false;
        //     }
        // }
        // return true;

        if(x < 0){
            return false;
        }
        long long ans = 0;
        long long num = x;
        while(num > 0){
            int rem = num % 10;
            num = num / 10;
            ans = ans*10 + rem;
        }
        if(ans == x){
            return true;
        }
        else{
            return false;
        }
    }
};
*/

// Roman to integer

/*
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int ans = 0;

        for(int i=0; i<s.length(); i++){
            if(m[s[i]] < m[s[i+1]]){
                ans -= m[s[i]];
            }
            else{
                ans += m[s[i]];
            }
        }
        return ans;
    }    
};
*/

// longest common prefix;
/*
        int len = strs.size() - 1;
        sort(strs.begin(), strs.end());
        string ans = "";
        string first = strs[0], last = strs[len];

        for (int i = 0;i<first.size(); i++) {
            if (strs[0][i] != strs[len][i]) {
                return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }
*/