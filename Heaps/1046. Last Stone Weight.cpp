// # Intuition
// Always smash the two heaviest stones.
// Use a max heap to efficiently get the largest elements.

// # Approach
// Push all stones into a max heap.
// While heap size > 1:
// Pop two largest stones x and y.
// If x != y → push (x - y) back.
// At the end:
// If one stone remains → return it.
// Else → return 0.

// # Complexity
// Time Complexity: O(n log n)
// Space Complexity: O(n)

// # Code
// ```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if((x-y)!=0){
                pq.push(x-y);
            }
        }
        if(pq.size()==1){
            return pq.top();
        }else{
            return 0;
        }
    }
};