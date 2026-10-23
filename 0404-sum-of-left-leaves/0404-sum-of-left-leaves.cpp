/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        if(!root) return 0;
        
        if(root->left != NULL && root->left->right==NULL && root->left->left==NULL){
            ans += root->left->val;
        }
        return ans+sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
    }
};