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
    TreeNode* buildTreePost(vector<int>& inorder,int is, int ie, vector<int>& postorder, int ps, int pe, map<int,int>&mp){
        if(is>ie || ps>pe) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int inroot = mp[postorder[pe]];
        int left = inroot-is;
        root->left = buildTreePost(inorder,is,inroot-1,postorder,ps, ps+left-1,mp);
        root->right = buildTreePost(inorder,inroot+1,ie,postorder,ps+left, pe-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() != inorder.size()){
            return NULL;
        }
        map<int,int>mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
       return buildTreePost(inorder,0,inorder.size()-1, postorder, 0, postorder.size()-1, mp);
    }
};