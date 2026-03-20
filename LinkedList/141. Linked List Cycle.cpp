// # Title
// Linked List Cycle Detection | Floyd’s Tortoise & Hare Algorithm 💡

// # Intuition
// If a cycle exists, a slow and a fast pointer will eventually meet.
// Fast moves 2 steps, slow moves 1 step → they collide inside the loop.

// # Approach
// Initialize two pointers slow and fast at head.
// Move slow by 1 step and fast by 2 steps.
// If they meet → return true (cycle exists).
// If fast reaches NULL → return false (no cycle).

// # Complexity
// Time Complexity: O(n)
// Space Complexity: O(1)

// # Code
// ```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};