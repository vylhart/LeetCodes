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
    void find(TreeNode* root, vector<int> &v){
        if(!root)   return;
        if(!root->left && root->right)  v.push_back(root->right->val); 
        if(root->left && !root->right)  v.push_back(root->left->val);
        find(root->left, v);
        find(root->right, v);
    }
    
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        find(root, ans);
        return ans;
    }
};