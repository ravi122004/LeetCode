// # Intuition
// We need k closest points based on distance from origin.
// Use a max heap to keep track of k closest points.
// If heap size exceeds k → remove farthest point.

// # Approach
// Use a max heap storing (distance, point).
// Traverse all points:
// Compute distance = x² + y².
// Push into heap.
// If heap size > k → pop top (farthest).
// Extract all points from heap into result.

// # Complexity
// Time Complexity: O(n log k)
// Space Complexity: O(k)

// # Code
// ```cpp
class Solution {
public:
    typedef pair<int,vector<int>> pi;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pi> pq;
        for(auto &p:points){
            int x=p[0];
            int y=p[1];
            int distance=(x*x)+(y*y);
            pair<int,vector<int>> pi={distance,p};
            pq.push(pi);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};