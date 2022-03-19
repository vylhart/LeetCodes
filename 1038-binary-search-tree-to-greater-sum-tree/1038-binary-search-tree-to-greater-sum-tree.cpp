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
    void find(TreeNode* root, int &ans){
        if(!root)   return;
        find(root->right, ans);
        ans += root->val;
        root->val = ans;
        find(root->left, ans);        
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int ans = 0;
        find(root, ans);
        return root;
    }
};