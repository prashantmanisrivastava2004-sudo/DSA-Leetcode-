/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }

        queue<TreeNode*> nodequeue;
        nodequeue.push(root);
        bool left_to_right = true;
        while (!nodequeue.empty()) {
            int n = nodequeue.size();
            vector<int> row(n);
            for (int i = 0; i < n; i++) {

                TreeNode* node = nodequeue.front();
                nodequeue.pop();
                int index = (left_to_right) ? i : (n - 1 - i);

                row[index] = node->val;

                if(node->left){
                    nodequeue.push(node->left);
                }
                if(node->right){
                    nodequeue.push(node->right);
                }
            }
            left_to_right = !left_to_right;
            result.push_back(row);
        }
        return result;
    }
};