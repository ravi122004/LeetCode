
class Solution {
public:
    void insert(TreeNode* &root,int val){
        if(root==NULL){
            root=new TreeNode(val);
            return;
        }
        else if(val>root->val){   //go right
            if(root->right==NULL){  //attach
                root->right=new TreeNode(val);
            }else{
                insert(root->right,val);
            }
        }else{
            if(root->left==NULL){  //attach
                root->left=new TreeNode(val);
            }else{
                insert(root->left,val);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insert(root,val);
        return root;
    }
};