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
#define MAX 100000

class Solution {
public:
    int findMin(TreeNode* A, int &prev){
        if(!A)  return MAX;
        int left = findMin(A->left, prev);
        int curr = abs(prev-A->val);
        prev = A->val;
        int right = findMin(A->right, prev);
        return min(curr, min(left, right));
    }
    
    int minDiffInBST(TreeNode* root) {
        int prev = MAX;
        return findMin(root, prev);
    }
};