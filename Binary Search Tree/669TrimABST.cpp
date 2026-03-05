/*Intuition
Because the tree is a Binary Search Tree (BST), every node follows this rule:
left subtree < root
right subtree > root
We are given a valid range [lo, hi] and must remove all nodes whose values fall outside this range.
Key observation:
If a node value is less than lo, then its entire left subtree is also < lo, so it can be discarded.
If a node value is greater than hi, then its entire right subtree is also > hi, so it can be discarded.
Instead of deleting nodes one by one, we redirect pointers to skip invalid nodes and connect the tree to the next valid candidate.
Your solution does this efficiently by iteratively fixing left and right children of every node.
A dummy node is used so that if the original root itself is outside the range, we can safely adjust the root pointer.

Approach
Use a Dummy Node

We create a dummy node whose left child is the original root.

This helps handle cases where the original root needs to be removed.

TreeNode* dummy = new TreeNode(INT_MAX);
dummy->left = root;
2️⃣ Fix the Left Subtree

While the left child exists:

If left->val < lo
→ discard it and move to its right child

If left->val > hi
→ discard it and move to its left child

Because of the BST property, these are the only valid directions to search for valid nodes.

3️⃣ Fix the Right Subtree

Similarly:

If right->val > hi
→ move to right->left

If right->val < lo
→ move to right->right

This removes all invalid nodes from the right side.

4️⃣ Recursively Trim Subtrees

Once the immediate children are valid, we recursively apply the same trimming process to:

left subtree

right subtree

Complexity
Time Complexity
O(N)
Each node is visited at most once.
Pointer adjustments ensure nodes are skipped efficiently.
So the total work is linear in the number of nodes.
Space Complexity:
O(H)
Due to recursion stack.
H = height of the tree.
Worst case (skewed tree)
O(N)

Balanced BST:
O(logN)
*/

class Solution {
public:
    void trim(TreeNode* root,int lo,int hi){
        if(root==NULL)return;
        while(root->left!=NULL){
            if(root->left->val<lo){
                root->left=root->left->right;
            }
            else if(root->left->val>hi){
                root->left=root->left->left;
            }
            else{
                break;
            }
        }
        while(root->right!=NULL){
            if(root->right->val>hi){
                root->right=root->right->left;
            }else if(root->right->val<lo){
                root->right=root->right->right;
            } 
                else{
                break;
            }
        }
        trim(root->left,lo,hi);
        trim(root->right,lo,hi);
    }
    TreeNode* trimBST(TreeNode* root, int lo, int hi) {
        TreeNode* dummy=new TreeNode(INT_MAX);
        dummy->left=root;
        trim(dummy,lo,hi);
        return dummy->left;
    }
};
