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
    void leaf(TreeNode* root, vector<int> &ans){
        if(!root)   return;
        if(!root->left && !root->right) ans.push_back(root->val);
        leaf(root->left, ans);
        leaf(root->right,ans);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1,arr2;
        leaf(root1, arr1);
        leaf(root2, arr2);
        if(arr1.size()!=arr2.size())    return 0;
        for(int i=0; i<arr1.size(); i++){
            if(arr1[i]!=arr2[i])    return 0;
        }
        return 1;
    }
};