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
    string dfs(TreeNode* root, string s){
        if(!root){
            return "zzzzzzz";
        }
        s = (char)(root->val+'a') + s;
        if(!root->left && !root->right) return s;
        string left  = dfs(root->left, s);
        string right = dfs(root->right, s);

        return (left<right ? left:right);        
    }
    
    string smallestFromLeaf(TreeNode* root) {
        return dfs(root, "");
    }
};