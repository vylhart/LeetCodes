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
    TreeNode* create(vector<int> &nums, int l, int h){
        if(l>h) return 0;
        int m = l;
        for(int i=l; i<=h; i++){
            if(nums[m]<nums[i]) m=i;
        }
        TreeNode* root = new TreeNode(nums[m]);
        root->left = create(nums, l, m-1);
        root->right= create(nums, m+1, h);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return create(nums, 0, nums.size()-1);
    }
};