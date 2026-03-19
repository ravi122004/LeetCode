// # Intuition
// We need to count pairs of strings where one is the reverse of the other.
// Instead of checking all pairs (O(n²)), we store seen words in a set.
// For each word, we reverse it and check if that reversed string already exists.
// If yes → we found a pair, otherwise store the current word.

// # Approach
// Initialize an unordered set to store seen words and a counter = 0.
// Traverse the array:
// Create reversed version of current string.
// If reversed string exists in set → increment count.
// Else insert current string into set.
// Return count.

// # Complexity
// Time Complexity: O(n * k) → k = length of string (reverse operation)
// Space Complexity: O(n)

// # Code
// ```cpp
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> s;
        int count=0;
        for(int i=0;i<words.size();i++){
            string rev=words[i];
            reverse(rev.begin(),rev.end());
            if(s.find(rev)!=s.end()) count++;
            else s.insert(words[i]);
        }
        return count;
    }
};