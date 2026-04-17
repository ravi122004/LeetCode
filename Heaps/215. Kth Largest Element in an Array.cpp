// # Intuition
// To find kth largest, maintain a min heap of size k.
// Smallest element in heap will be the kth largest overall.

// # Approach
// Use a min heap.
// Traverse array:
// Push each element into heap.
// If heap size > k → pop smallest.
// At the end, top of heap is kth largest element.

// # Complexity
// Time Complexity: O(n log k)
// Space Complexity: O(k)

// # Code
// ```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};