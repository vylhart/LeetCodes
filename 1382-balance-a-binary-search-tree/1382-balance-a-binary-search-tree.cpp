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
    void dfs(TreeNode* root, vector<TreeNode*> &ans){
        if(!root) return;
        dfs(root->left, ans);
        ans.push_back(root);
        dfs(root->right, ans);
        root->left = root->right = 0 ;
        
    }
    
    TreeNode* create(vector<TreeNode*> &ans, int l, int h){
        if(l>h) return 0;
        int m = (l+h)/2;
        TreeNode* root = ans[m];
        root->left = create(ans, l, m-1);
        root->right= create(ans,m+1, h);
        return root;
    }
    
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> array;
        dfs(root, array);
        return create(array, 0, array.size()-1);
    }
};