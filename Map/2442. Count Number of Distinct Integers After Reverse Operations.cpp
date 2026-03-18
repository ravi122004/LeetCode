Approach
We need to count all unique integers after including both original numbers and their reversed values.
Use an unordered set to automatically store only distinct values.
For each number in the array:

Insert the original number into the set
Reverse its digits using modulo (% 10) and division (/ 10)
Insert the reversed number into the set
Finally, return the size of the set.
Complexity
⚙️ Time Complexity
O(n × d), where n = number of elements and d = number of digits in each number.
Since digits are at most 10 (int range), we treat it as O(n).

🗂️ Space Complexity
O(n) → for storing distinct elements in the set

Code
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int size=nums.size();
        unordered_set<int>st;
        for(int i=0;i<size;i++){

            int n=nums[i];
            st.insert(n);
            int rev=0;
            while(n!=0){
                int digit=n%10;
                rev=rev*10+digit;
                n=n/10;
            }
            st.insert(rev);            

        }
        return st.size();
    }
};