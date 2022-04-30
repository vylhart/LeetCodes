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
    int find(TreeNode* root, int &c, int k){
        if(!root)    return -1;
        int left = find(root->left, c, k);
        if(left!=-1)    return left;
        c++;
        if(c==k)    return root->val;
        int right= find(root->right,c, k);
        return right;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        return find(root, c, k);
    }
};