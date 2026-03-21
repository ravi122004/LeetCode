// # Title
// Find Middle of Linked List | Slow & Fast Pointer Trick 

// # Intuition
// Using two pointers, fast moves twice as fast as slow.
// When fast reaches the end, slow will be at the middle.

// # Approach
// Initialize slow and fast at head.
// Move slow by 1 step and fast by 2 steps.
// When fast reaches NULL (or end), slow points to the middle.
// Return slow.

// # Complexity
// Time Complexity: O(n)
// Space Complexity: O(1)

// # Code
// ```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};