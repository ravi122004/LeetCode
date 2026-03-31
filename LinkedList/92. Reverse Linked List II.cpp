// # Intuition
// We only reverse a specific portion of the list (from left to right).
// Break the list into three parts:
// Before sublist, sublist, after sublist.
// Reverse the middle part and reconnect all parts.

// # Approach
// Traverse the list and mark four nodes:
// a → node before left
// b → node at left
// c → node at right
// d → node after right
// Disconnect the sublist:
// a->next = NULL (if exists)
// c->next = NULL
// Reverse the sublist starting from b.
// Reconnect:
// If a exists → connect a->next to new head.
// Connect end of reversed sublist (b) to d.
// Return head if a exists, else new head.

// # Complexity
// Time Complexity: O(n)
// Space Complexity: O(1)

// # Code
// ```cpp
ListNode* reverse(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
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

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* a=NULL;
        ListNode* b=NULL;
        ListNode* c=NULL;
        ListNode* d=NULL;
        ListNode* temp=head;
        int n=1;
        while(temp){
            if(n==left-1) a=temp;
            if(n==left) b=temp;
            if(n==right) c=temp;
            if(n==right+1) d=temp;
            temp=temp->next;
            n++;
        }
        if(a) a->next=NULL;
        c->next=NULL;
        c=reverse(b);
        if(a) a->next=c;
        b->next=d;
        return a? head:c;
    }
};