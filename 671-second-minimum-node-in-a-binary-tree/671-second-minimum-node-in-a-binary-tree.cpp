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
    void dfs(TreeNode* root, long &first, long &second){
        if(!root)   return;
        if(root->val<first){
            second = first;
            first = root->val;
        }
        else if(root->val < second && root->val!=first){
            second = root->val;
        }
        dfs(root->left, first, second);
        dfs(root->right,first, second);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        long MAX = (long)3e9;
        long first=MAX, second=MAX;
        dfs(root, first, second);
        return second==MAX? -1:second;
    }
};