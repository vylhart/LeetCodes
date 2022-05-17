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
    void dfs(TreeNode* root, int &ans){
        if(!root)   return;
        dfs(root->right, ans);
        ans += root->val;
        root->val =ans;
        dfs(root->left, ans);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int ans=0;
        dfs(root, ans);
        return root;
    }
};