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
/*
0 - Unmonitored
1 - Monitored
2 - Camera
*/
class Solution {
    int count = 0;
public:
    int find(TreeNode* root){
        if(!root)   return 1;
        int l = find(root->left);
        int r = find(root->right);
        
        if(l==0 || r==0){
            count++;
            return 2;
        }
        else if(l==2 || r==2){
            return 1;
        }
        return 0;
    }  
    int minCameraCover(TreeNode* root) {
        count += find(root)==0;
        return count;
    }
};