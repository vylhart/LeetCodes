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
    int ans;
    class Res{
        public:
        int min, max, isBST;
    };
public:
    Res find(TreeNode* root){
        Res res;
        
        if(!root){
            res.min = INT_MAX;res.max = INT_MIN;res.isBST = 0;
            return res;
        }
        
        Res left =  find(root->left);
        Res right = find(root->right);
        
        res.min = min({root->val, left.min, right.min});
        res.max = max({root->val, left.max, right.max});
        
        
        if(left.isBST!=-1 && right.isBST!=-1 && left.max < root->val && root->val < right.min)
            res.isBST = left.isBST + right.isBST + 1; 
        else
            res.isBST = -1;
        ans = max(ans, res.isBST);
        return res;
    }
    
    int largestBSTSubtree(TreeNode* root) {
        ans=0;
        find(root);
        return ans;
    }
};