// # Intuition
// Reversing a linked list is all about changing the direction of pointers.
// Normally, each node points to the next node → we flip it so that each node points to the previous one.
// Think of it like walking forward in a line, but at each step, you turn back and connect to the previous person 👀
// To do this safely, we need three pointers:
// prev → stores previous node
// curr → current node
// next → temporarily stores next node (so we don’t lose the list)

// # Approach
// Initialize:
// prev = NULL
// curr = head

// Traverse the list:
// Store next node → next = curr->next
// Reverse link → curr->next = prev
// Move prev forward → prev = curr
// Move curr forward → curr = next

// When traversal ends:
// prev will be the new head

// # Complexity
// Time Complexity: O(n) → We traverse the list once
// Space Complexity: O(1) → No extra space used (in-place reversal)

// # Code
// ```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* Next=head;

        while(curr){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
    }
};