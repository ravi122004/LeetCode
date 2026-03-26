// # Title
// 🔥 Decode Message Using Substitution Cipher | Hash Map Mapping 💡

// # Intuition
// The key defines a mapping from characters to 'a' → 'z' based on first appearance.
// We build this mapping and then decode the message using it.

// # Approach
// Create an unordered_map for character mapping.
// Initialize ch = 'a'.
// Traverse key:
// If character is not space and not already mapped:
// Assign it to current ch and increment ch.
// Traverse message:
// If space → add space.
// Else → replace using map.
// Return decoded string.

// # Complexity
// Time Complexity: O(n + m)
// Space Complexity: O(1)

// # Code
// ```cpp
class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> mp;
        char ch='a';
        for(int i=0;i<key.size();i++){
            if(key[i]!=' ' && mp.find(key[i])==mp.end()){
                mp[key[i]]=ch;
                ch++;
            }
        }
        string ans="";
        for(int i=0;i<message.size();i++){
            if(message[i]==' '){
                ans+=' ';
            }else{
                ans+=mp[message[i]];
            }
        }
        return ans;
    }
};