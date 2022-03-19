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
    void find(TreeNode* root, int h, int &maxH, int &ans){
        if(!root)   return;
        if(h>maxH){
            ans = 0;
            maxH = h;
        }
        
        if(h==maxH)    ans+= root->val;
        
        find(root->left, h+1, maxH, ans);
        find(root->right,h+1, maxH, ans);
    }
    
    
    int deepestLeavesSum(TreeNode* root) {
        int h=0, maxH=0, ans=0;
        find(root, h, maxH, ans);
        return ans;
    }
};