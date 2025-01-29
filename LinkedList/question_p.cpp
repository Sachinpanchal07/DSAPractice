#include<iostream>
using namespace std;


// reverse LL using k groups.
// void reverse(Node* head, int k){
//     // base case
//     if (head == NULL){
//         return NULL;
//     }
//     // step1 
//     int count = 1;
//     Node* prev = NULL;
//     Node* curr = head;
//     Node* forward = NULL;
//     while(curr != NULL && count <= k){
//         forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;
//         count++;
//     }
//     // step2
//     if(forward != NULL){
//         head->next = reverse(forward, k);
//     }
//     return prev;
// }

// ============================ is LL circular =====================

// bool isCircular(Node* head){
//     if(head == NULL){
//         return true;
//     }
//     Node* temp = head;
//     while(temp != NULL && temp != head){
//         temp = temp->next;
//     }
//     if(temp == head){
//         return true;
//     }
//     else{
//         return false;
//     }
// }
