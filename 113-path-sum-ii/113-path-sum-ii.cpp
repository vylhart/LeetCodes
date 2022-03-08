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
    void find(TreeNode* root, int t, vector<int> curr, vector<vector<int>> &ans){
        if(!root)   return;
        curr.push_back(root->val);
        t-=root->val;
        if(!root->left && !root->right && t == 0){
            ans.push_back(curr);
        }
        find(root->left,  t, curr, ans);
        find(root->right, t, curr, ans);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr;
        vector<vector<int>> ans;
        find(root, targetSum, curr, ans);
        return ans;
    }
};