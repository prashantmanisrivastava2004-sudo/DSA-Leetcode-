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
    vector<string> binaryTreePaths(TreeNode* root) {
       vector<string>ans;
        if(root == NULL) return ans;
        stack<pair<TreeNode*, string>> st;
        st.push({root, to_string(root->val)});
       
       while(!st.empty()){
          
          TreeNode* curr = st.top().first;
          string s = st.top().second;
          st.pop();
          if(curr->left==NULL && curr->right==NULL){
            ans.push_back(s);
          }
          if(curr->right != NULL){
            st.push({curr->right, s + "->" + to_string(curr->right->val)});
          }
          if(curr->left != NULL){
            st.push({curr->left, s + "->" + to_string(curr->left->val)});
          }
       }
       return ans;
    }
};