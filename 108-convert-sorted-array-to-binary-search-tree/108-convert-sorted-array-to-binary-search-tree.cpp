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
    TreeNode* createTree(vector<int> &nums, int l, int h){
        if(l>h) return 0;
        int m = (l+h)/2;
        TreeNode* curr = new TreeNode(nums[m]);
        curr->left = createTree(nums, l,  m-1);
        curr->right= createTree(nums, m+1,h);
        return curr;   
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createTree(nums, 0, nums.size()-1);
    }
};