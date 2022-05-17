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
    int dfs(TreeNode* root, int x){
        if(!root)   return 0;
        x = x*10+root->val;
        if(!root->left &&!root->right){
            return x;
        }
        return dfs(root->left,x)+dfs(root->right,x);
    }
    
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};