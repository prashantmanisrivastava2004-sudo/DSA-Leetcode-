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

     TreeNode* iop(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right != NULL){
            pred = pred->right;
        }
        return pred;
    }
    TreeNode* deleteNode(TreeNode* root, int x) {
        if(!root) return NULL;
        if(root->val == x){
            //leaf node
            if(root->left==NULL && root->right==NULL){
               return NULL;
            }
            //one child
            if(root->left==NULL || root->right==NULL){
                if(root->left != NULL) return root->left;
                else return root->right;
            }
            //two child then replace node with inorder succ or predecessor
            else{
                TreeNode* pred = iop(root);
                root->val = pred->val;
                root->left = deleteNode(root->left, pred->val);
            }
        }
        
       else if(root->val > x){
            root->left = deleteNode(root->left,x);
        }
        else{
            root->right = deleteNode(root->right,x);
        }
        return root;
    }
};