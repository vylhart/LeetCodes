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
    void check(TreeNode* root, int x, int y, int &h1, int &h2, int h){
        if(!root)   return;
        if(root->val==x)    h1=h;
        if(root->val==y)    h2=h;
        if(root->left && root->right){
            if(root->left->val==x && root->right->val==y)   return;
            if(root->left->val==y && root->right->val==x)   return;
        }
        check(root->left,  x, y, h1, h2, h+1);
        check(root->right, x, y, h1, h2, h+1);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int h1=-1, h2=-1;
        check(root, x, y, h1, h2, 0);
        if(h1==h2 && h1!=-1)    return 1;
        return 0;
    }
};