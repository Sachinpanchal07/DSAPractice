#include<iostream>
#include<map>
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

// =========================== detect loop in LL ===================== 

// bool detectLoop(Node* head){
//     if(head == NULL){
//         return false;
//     }
//     map<Node*, bool> visited;
//     Node* temp = head;
//     while(temp != NULL){
//         if(visited[temp] == true){
//             cout << temp->data << " "; // this will tell which node create the cycle.
//             cout << "cycle is detected";
//             return false;
//         }
//         temp = temp->next;   
//     }
//     return true;
// }

// ======================= detect loop with slow and fast poiners ==================

/*Node* detectCycle(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;

    while(slow != fast && fast != NULL){
        fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}*/

// =========================== detect which node create cycle ====================

/*bool nodeCreateCycle(Node* head){
    if (head == NULL){
        return false;
    }
    Node* intersection = detectCycle(head); // call above function.
    Node* slow = head;
    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;//this is the point where intersection and slow meets again,and this point is cycle creator
}*/

// ============================ Remove cycle in LL =======================

/*void removeCycle(Node* head){
    if(head == NULL){
        return;
    }
    Node* intersect = nodeCreateCycle(head); // call above function.
    Node* temp = intersect;
    while(temp->next != intersect){
        temp = temp-next;
    }
    temp-next = NULL; // remove cycle here.
}*/