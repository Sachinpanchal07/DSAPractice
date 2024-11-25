#include <iostream>
#include <string>
using namespace std;

//============================ char arrays ==================================

// ================== check palindrome =========================
// int main(){
//     char a[5] = {'a','b','c','b','a'};
//     int s = 0;
//     int e = 4;
//     bool pal = true;
//     while(s<e){
//         if(a[s]!=a[e]){
//             pal = false;
//             break;
//         }
//         s++;
//         e--;
//     }
//     if(pal == true){
//         cout << "palindrome";
//     }else{
//         cout << "not palindrome";
//     }
// }

// ============================ find max character in string ==============================

int main()
{

    string inp = "a bb ccc dddd ffffffff";
    int arr[26] = {0};
    int max = -1;
    int maxIndex = -1;
    // finding freq of letters
    for (char str : inp)
    {
        if (str == ' ')
        {
            continue;
        }
        else
        {
            int num = str - 'a';
            arr[num]++;
            // cout << num << endl;
        }
    }
    // finding max freq index and max freq
    for(int i=0; i<26; i++){
        if(max < arr[i]){
            max = arr[i];
            maxIndex = i;
        }
    }
    char output = maxIndex +'a';
    
    cout << "maximum times the character occured is: " << output;
}