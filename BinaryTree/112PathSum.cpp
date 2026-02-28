
class Solution {
public:
    bool helper(TreeNode* root,int sum){
        if(root==NULL)return false;
        if(root->left==NULL &&root->right==NULL){
            if(root->val==sum){
                return true;
            }
        }
        return(helper(root->left,sum-root->val)||
        helper(root->right,sum-root->val));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return helper(root,targetSum);
        
    }
};