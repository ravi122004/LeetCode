
/*Tree Traversal with Recursive Path Counting | CPP
Approach
In this problem, a valid path can start from any node in the tree, but it must move downward.
To solve this, I used a recursive approach:
Create a helper function that:
Checks if the current node completes the required sum.
Recursively explores left and right subtrees with the remaining sum.
For every node:
Count paths starting from that node.
Then recursively apply the same logic to its left and right children.
This ensures we consider all possible starting points in the tree.
Complexity
Time complexity:
Worst Case: O(n²)
Space complexity:
O(h)

Where h = height of the tree.
In worst case (skewed tree) → O(n)
In balanced tree → O(log n)
*/


class Solution {
public:
    void helper(TreeNode* root,long long targetSum,int& count){
        if(root==NULL)return ;
        if(root->val==targetSum){
            count++;
        }
        helper(root->left,targetSum-root->val,count);
        helper(root->right,targetSum-root->val,count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;
        int count=0;
        helper(root,targetSum,count);
        count+=pathSum(root->left,targetSum);
        count+=pathSum(root->right,targetSum);
        return count;

    }
};