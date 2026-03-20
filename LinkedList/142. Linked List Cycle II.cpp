// # Title
//  Detect Cycle in Linked List II | Floyd’s Cycle Detection (Tortoise & Hare) 💡

// # Intuition
// If a cycle exists, slow and fast pointers will meet inside the loop.
// Once they meet, moving one pointer from head and the other from meeting point will lead them to the cycle start.
// That meeting point is the node where the cycle begins.

// # Approach
// Initialize two pointers slow and fast at head.
// Move slow by 1 step and fast by 2 steps.
// If they meet → cycle exists.
// If no cycle → return NULL.
// To find cycle start:
// Initialize temp at head.
// Move both slow and temp one step at a time.
// Where they meet → start of cycle.
// Return that node.

// # Complexity
// Time Complexity: O(n)
// Space Complexity: O(1)

// # Code
// ```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=head;
        bool flag=false;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                flag=true;
                break;
            }
        }
        if(flag){
            while(temp!=slow){
                slow=slow->next;
                temp=temp->next;
            }
            return temp;
        }else{
            return NULL;
        }
    }
};