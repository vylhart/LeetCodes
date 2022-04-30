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
    
    void dfs(TreeNode* root, TreeNode* &prev){
        if(!root)   return;
        prev->right = root;
        prev->left = 0;
        prev = root;
        TreeNode* right = root->right;
        dfs(root->left, prev);        
        dfs(right, prev);
    }
    
    void flatten(TreeNode* root) {
        TreeNode* prev = new TreeNode(0);
        dfs(root, prev);
    }
};