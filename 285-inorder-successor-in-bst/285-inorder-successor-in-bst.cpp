/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void find(TreeNode* root, TreeNode* p, TreeNode* &ans){
        if(!root)   return;
        if(root->val > p->val){
            ans = root;
            find(root->left, p, ans);
            return;
        }
        else{
            find(root->right, p, ans);
        }
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {      
        TreeNode* ans = 0;
        find(root, p, ans);
        return ans;
    }
};