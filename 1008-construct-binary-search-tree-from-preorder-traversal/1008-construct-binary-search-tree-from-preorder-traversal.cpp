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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(preorder[0]);
        s.push(root);
        for(int i=1; i<preorder.size(); i++){
            TreeNode* node = s.top();
            TreeNode* child = new TreeNode(preorder[i]);
            while(!s.empty() && s.top()->val < child->val){
                node = s.top();
                s.pop();
            }
            if(node->val < child->val){
                node->right = child;
            }
            else{
                node->left = child;
            }
            s.push(child);
        }
        return root;
    }
};