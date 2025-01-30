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

// =============================== Remove duplicates in Sorted LL ==================
/*
Node* removeDuplicate(Node* head){
    if (head == NULL){
        return head;
    }
    else if(head ->next == NULL){
        return head;
    }
    Node* curr = head;
    while(curr->next != NULL){
        if(curr->data == curr->next->data){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}
*/

// ======================== sort 0's 1's 2's LL ========================
/*
Node* sort(Node*& head){
    if(head == NULL){
        return NULL;
    }
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            zeroCount++;
        }
        else if(temp->data == 1){
            oneCount++;
        }
        else{
            twoCount++;
        }
        temp = temp->next;
    }
    temp = head;

    while(temp != NULL){
        if(zeroCount != 0){
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0){
            temp->data = 1;
            oneCount--;
        }
        else if(twoCount != 0){
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;
}
*/

// ======================= sort 0s 1s 2s LL without data replacement ===================

// insertAtTail function-> add value in new LL's
/*
        void insertAtTail( Node* &tail, Node* curr){
            tail->next = curr;
            tail = curr;
        }

    Node* sort(Node* head){
        // intialize three dummy nodes
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;

        // add values in these three nodes
        Node* curr = head;
        while(curr != NULL){
            int value = curr->data;
            if(value == 0){
                insertAtTail(zeroTail,curr );
            }
            else if(value == 1){
                insertAtTail(oneTail, curr );
            }
            else if(value == 2) {
                insertAtTail(twoTail, curr );
            }
            curr = curr->next;
        }

        // merge these LL's
        if(oneHead->next != NULL){
            zeroTail->next = oneHead->next;
        }
        else{
            zeroTail->next = twoHead->next;
        }

        oneTail->next = twoHead->next;
        twoTail->next = NULL;
        
        // delete dummy nodes.
        head = zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return head;
    }
    */

// ======================= merge two sorted Linked list ===================
// fuction to solve
/*
Node* solve(Node* &first, Node* &second){
    // if only one element in first LL.
    if(first->next == NULL){
        first->next = second;
        return first;
    }

    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2 = second;
    Node* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL){
        // check first element of second LL and compare with first LL.
        if(curr1->data <= curr2->data && curr2->data <= next1->data){
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr1->next;
            curr2 = next2;
        }
        else{
            curr1 = curr1->next;
            next1 = next1->next;
            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node* merge(Node* first, Node* second){
    // we take 'first' LL which has first small element. 
    if(first->data <= second->data){
        return solve(first, second);
    }
    else{
        return solve(second, first);
    }
}
*/

// ============================== check palindrome ============================

// find mid funciton
Node* getMid(Node*& head){
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
// reverse the half LL
Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* forword = NULL;
    while(curr != NULL){
        forword = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forword;
    }
    return prev;
}

bool palindrome(Node* head){
    if(head == NULL || head->next == NULL){
        return true;
    }
    Node* mid = getMid(head); // get the mid

    Node* newHead = reverse(mid->next); // reverse half LL
    Node* first = head;
    Node* second = newHead;

    // compare both halfs
     while(second != NULL){
        if(first->data != second->data){
            reverse(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    // reverse LL again.
    reverse(newHead);
    return true;
}