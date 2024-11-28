#include<iostream>
using namespace std;

// int main(){

    // =================  create 2d array, 3 rows and 3 columns

    // int arr[3][4]; 

    //     int arr[2][3] = {
    //     {1, 2, 3},
    //     {4, 5, 6}
    // };

    // int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    // ================= taking input from user on base of rows for 2d array

    // for(int row=0; row<3; row++){
    //     for(int col=0; col<4; col++){
    //         cin >> arr[row][col];
    //     }
    // }

    // ================= taking input from user on base of columns for 2d array

    // for(int col=0; col<4; col++){
    //     for(int row=0; row<3; row++){
    //         cin >> arr[row][col];
    //     }
    // }

    // ================= printing output of 2d array
    // for(int row=0; row<3; row++){
    //     for(int col=0; col<4; col++){
    //         cout << arr[row][col] << " ";
    //     }
    //     cout << endl;
    // }
// }

// ============================================= Question practice ===============================================

// ========================= searching element in 2d array ============================
// int ispresent(int arr[][4], int key, int row, int col){
//     for(int row=0; row<3; row++){
//         for(int col=0; col<4; col++){
//             if(arr[row][col] == key){
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }
// int main(){
//     int arr[3][4];
//     cout << "enter the array: " << " ";
//     for(int row=0; row<3; row++){
//         for(int col=0; col<4; col++){
//             cin >> arr[row][col];
//         }
//     }
//     for(int row=0; row<3; row++){
//         for(int col=0; col<4; col++){
//             cout << arr[row][col] << " ";
//         }
//         cout << endl;
//     }

//     int key;
//     cout << "enter the value: ";
//     cin >> key;
//     if(ispresent(arr, key, 3, 4)){
//         cout << "found";
//     }
//     else{
//         cout << "not found";
//     }

// }

// ==================================== adding sum of row ========================================
// void sum(int arr[][4], int row, int col){
//     int sum = 0;
//     for(int row=0; row<3; row++){
//         for(int col=0; col<4; col++){
//             sum += arr[row][col];
//         }
//         cout << "sum of line: "<< row << " is "<< sum << endl;
//         sum = 0;
//     }
    
// }
// int main(){
//     int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
//     for(int row=0; row<3; row++){
//         for(int col=0; col<4; col++){
//             cout << arr[row][col] << " ";
//         }
//         cout << endl;
//     }
//     sum(arr,3,4);

// }

// =========================================== wave sum of columns ================================================

// void waveSum(int arr[][4], int nrow, int mcol){
//     for(int col=0; col<mcol; col++){

//         // if col is odd, travers bottom to top
//         if((col%2)!=0){
//             for(int row=nrow-1; row>=0; row--){
//                 cout << arr[row][col] << " ";
//             }
//         }
//         // if col is even, travers top to bottom
//         else{
//             for(int row=0; row<nrow; row++){
//                 cout << arr[row][col] << " ";
//             }
//         }
//         cout << endl;
//     }
// }

// int main(){

//     int arr[3][4]= {1,2,3,4,5,6,7,8,9,10,11,12};

//     for(int i=0; i<3; i++){
//         for (int j=0; j<4; j++){
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << "======================" << endl;
//     waveSum(arr, 3, 4);
// }

// ===================================== spiral traverse in matrix =====================================

// void spiralTraverse(int arr[][4], int nrow, int mcol){
//     int count = 0;
//     int total_elements = nrow * mcol;

//     int starting_row = 0;
//     int ending_row = nrow - 1;
//     int starting_col = 0;
//     int ending_col = mcol-1;

//     while (count < total_elements)
//     {
//         // print starting row, check count sath sath taki count total se aage na nikal jaye
//         for(int index=starting_col; count<total_elements && index<=ending_col; index++){
//             cout << arr[starting_row][index] << " ";
//             count++;
//         }
//         starting_row++;

//         // print ending col
//         for(int index=starting_row; count<total_elements && index<=ending_row; index++){
//             cout << arr[index][ending_col] <<" ";
//             count++;
//         }
//         ending_col--;
        
//         // print ending row in reverse
//         for(int index=ending_col; count<total_elements && index>=starting_col; index--){
//             cout << arr[ending_row][index] << " ";
//             count++;
//         }
//         ending_row--;

//         // print starting col in reverse
//         for(int index=ending_row; count<total_elements && index>=starting_row; index--){
//             cout << arr[index][starting_col] << " ";
//             count++;
//         }
//         starting_col++;
//     }
    
// }

// int main(){

//     int arr[3][4]= {1,2,3,4,5,6,7,8,9,10,11,12};

//     for(int i=0; i<3; i++){
//         for (int j=0; j<4; j++){
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << "======================" << endl;
//     spiralTraverse(arr, 3, 4);
// }