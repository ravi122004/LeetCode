// # Title
// 🔥 Valid Anagram in O(n) | Hash Map Counting Trick 💡

// # Intuition
// Two strings are anagrams if they have the same characters with the same frequency.
// We count characters of the first string and try to cancel them using the second string.
// If everything cancels out perfectly → anagram, otherwise not.

// # Approach
// Create an unordered_map to store frequency of characters from string s.
// Traverse s and increment count of each character.
// Traverse t:
// If character exists in map → decrement its count.
// If count becomes 0 → erase it from map.
// If character not found → return false.
// At the end, if map is empty → return true, else false.

// # Complexity
// Time Complexity: O(n)
// Space Complexity: O(1) → at most 26 characters (for lowercase letters)

// # Code
// ```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            char ch=t[i];
            if(mp.find(ch)!=mp.end()){
                mp[ch]--;
                if(mp[ch]==0) mp.erase(ch);
            }else{
                return false;
            }
        }
        if(mp.size()==0) return true;
        return false;
    }
};