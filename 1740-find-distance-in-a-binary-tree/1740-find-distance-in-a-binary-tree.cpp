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
    TreeNode* lca(TreeNode* root, int p, int q){
        if(!root)   return 0;
        TreeNode* left  = lca(root->left,  p, q);
        TreeNode* right = lca(root->right, p, q);
        if((root->val == p || root->val==q))   return root;
        else if(left && right)  return root;
        else if(left) return left;
        else if(right) return right;
        return 0;        
    }
    
    int height(TreeNode* root, int x, int d){
        if(!root)   return 0;
        if(root->val == x)  return d;
        return max(height(root->left, x, d+1), height(root->right, x, d+1));
    }
    
    int findDistance(TreeNode* root, int p, int q) {
        if(p==q)    return 0;
        int a = lca(root, p, q)->val;
        //cout<<height(root, a,0);
        return height(root, p,0)+height(root, q,0)-2*height(root, a,0);
    }
    

};


//Assuming 
//both p and q exists
//unique
