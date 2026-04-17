// # Intuition
// We need k elements with highest frequency.
// Use a min heap of size k to keep track of top frequencies.
// If heap exceeds k → remove smallest frequency.

// # Approach
// Count frequency using unordered_map.
// Use a min heap storing (frequency, element).
// Traverse map:
// Push pair into heap.
// If heap size > k → pop smallest.
// Extract elements from heap into result.

// # Complexity
// Time Complexity: O(n log k)
// Space Complexity: O(n)

// # Code
// ```cpp
class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(auto x:mp){
            int freq=x.second;
            int ele=x.first;
            pair<int,int> p={freq,ele};
            pq.push(p);
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(pq.size()>0){
            int ele=pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }
};