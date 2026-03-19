// # Title
// 🔥 Unique Number of Occurrences | Hash Map + Set Trick 💡

// # Intuition
// We count how many times each number appears.
// Then we check if all frequencies are unique.
// If any frequency repeats → return false.

// # Approach
// Create an unordered_map to store frequency of each number.
// Traverse the array and fill the map.
// Create an unordered_set to track frequencies.
// Traverse the map:
// If frequency already exists in set → return false.
// Else insert frequency into set.
// If all frequencies are unique → return true.

// # Complexity
// Time Complexity: O(n)
// Space Complexity: O(n)

// # Code
// ```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        unordered_set<int> s;
        for(auto x:mp){
            int freq=x.second;
            if(s.find(freq)!=s.end()) return false;
            else s.insert(freq);
        }
        return true;
    }
};