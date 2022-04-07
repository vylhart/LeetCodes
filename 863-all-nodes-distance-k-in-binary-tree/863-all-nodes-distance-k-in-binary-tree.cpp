/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        if(!root)   return;
        if(root->left){
            parent[root->left] = root;
            dfs(root->left, parent);
        }      
        if(root->right){
            parent[root->right] = root;
            dfs(root->right, parent);
        }     
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        queue<pair<TreeNode*, int>> q;
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, int> vis;
        dfs(root, parent);
        vector<int> ans;
        if(root)    q.push({target, 0});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int d = q.front().second;
            q.pop();
            if(vis[node])   continue;
            if(d==k)    ans.push_back(node->val);
            vis[node] = 1;
            if(node->left)  q.push({node->left, d+1});
            if(node->right)  q.push({node->right, d+1});
            if(parent[node])  q.push({parent[node], d+1});
        }
        return ans;
        
    }
};