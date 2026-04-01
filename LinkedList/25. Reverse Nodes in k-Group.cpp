// # Intuition
// We reverse nodes in groups of size k.
// If less than k nodes remain → keep them as it is.
// Use recursion to process remaining list after reversing current k nodes.

// # Approach
// Check if at least k nodes exist:
// Traverse k nodes using a temp pointer.
// If count < k → return head (no reversal).
// Reverse first k nodes using helper function.
// Connect:
// Original head becomes tail → connect it to result of next recursive call.
// Return new head of reversed group.

// # Complexity
// Time Complexity: O(n)
// Space Complexity: O(n/k) → recursion stack

// # Code
// ```cpp
ListNode* reverse(ListNode* head,int k){
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* Next=NULL;
    while(curr && k--){
        Next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=Next;
    }
    return prev;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        int count=0;
        while(temp && count<k){
            count++;
            temp=temp->next;
        }
        if(count<k) return head;
        ListNode* newHead=reverse(head,k);
        head->next=reverseKGroup(temp,k);
        return newHead;
    }
};