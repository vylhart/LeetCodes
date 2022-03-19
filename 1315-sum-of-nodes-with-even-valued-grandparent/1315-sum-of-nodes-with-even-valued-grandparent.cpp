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
    int sumEvenGrandparent(TreeNode* root) {
        if(!root)   return 0;
        int sum=0;
        if(root->val%2==0){
            TreeNode* left = root->left;
            if(left){
                if(left->left)   sum+= left->left->val;
                if(left->right)  sum+= left->right->val;
            }
            
            TreeNode* right = root->right;
            if(right){
                if(right->left)   sum+= right->left->val;    
                if(right->right)  sum+= right->right->val;    
            }
        }
        sum+= sumEvenGrandparent(root->left);
        sum+= sumEvenGrandparent(root->right);
        return sum;
    }
};