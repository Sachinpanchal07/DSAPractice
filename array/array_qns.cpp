#include<iostream>
#include<vector>
#include<string>
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

// SEARCH INSERT POSITION
/*
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    int s = 0;
    int e = nums.size() - 1;

    while(s<=e){
        int m = s + (e-s)/2;
        if (nums[m] == target){
            return m;
        }
        else if(target < nums[m]){
            e = m - 1;
        }
        else{
            s  = m + 1;
        }
    }
    return s;
    }
};
*/

// LENGTH OF LAST WORD
/*
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[0] == ' ' && s.length() == 1) {
                return 0;
            } else if (s.length() == 1) {
                return 1;
            } else if (s[i] == ' ') {
                continue;
            } else {
                while (s[i] != ' ') {
                    ans += 1;
                    i--;
                }
                return ans;

            }
        }
        return ans;
    }
};
*/

// Plus one

/*
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] + 1 != 10) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
            if (i == 0) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }
        return digits;
    }
};
*/

// pascel trinagle
 /*
 class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++){
            vector<int> v(i+1, 1);
            for(int j=1; j<i; j++){
                v[j] = ans[i-1][j] + ans[i-1][j-1];
            }
            ans.push_back(v);
        }
        return ans;
    }
};
 */

// single number

/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto x:nums){
            ans = ans^x;
        }
        return ans;
    }
};
*/

// Majority element 
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int el = 0;
        for(int i=0; i<nums.size(); i++){
            if(count == 0){
                el = nums[i];
                count = 1;
            }
            else if(el = nums[i]){
                count++;
            }
            else{
                count--
            }
        }
        return el;
    }
};
*/

// constain dubplicate 2
/*
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m; 
        m.insert({nums[0],0});
        for(int i=1; i<nums.size(); i++){
            if(m.count(nums[i]) && abs(m.at(nums[i]) - i) <= k){
                return true;
            }
            else{
                m[nums[i]] = i;
            }
        }
        return false;
    }
};
*/

