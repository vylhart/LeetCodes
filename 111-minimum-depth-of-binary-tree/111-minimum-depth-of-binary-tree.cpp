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
    int mDepth(TreeNode* root) {
        if(!root) return 100000;
        if(!root->left && !root->right) return 1;
        return min(mDepth(root->left), mDepth(root->right))+1;
    }
    
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return mDepth(root);
    }
};