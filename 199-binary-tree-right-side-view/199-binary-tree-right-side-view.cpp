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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> left;
        queue<pair<TreeNode*, int>> q;
        if(root)
            q.push({root, 0});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int d = q.front().second;
            q.pop();
            if(left.size()==d){
                left.push_back(node->val);
            }
            if(node->right) q.push({node->right,d+1});
            if(node->left) q.push({node->left, d+1});
            
        }
        return left;
    }
};