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
    void dfs(TreeNode* root, int p, int &m){
        if(!root)   return;
        m = max(m, p);
        dfs(root->left, p+1, m);
        dfs(root->right, p-1, m);
    }
    
    void bfs(TreeNode* root, int p, vector<vector<int>> &ans){
        if(!root)   return;
        queue<pair<TreeNode*, int>> q;
        q.push({root, p});
        while(!q.empty()){
            root = q.front().first;
            p = q.front().second;
            q.pop();
            if(p==ans.size()){
                ans.push_back({root->val});
            }
            else{
                ans[p].push_back(root->val);
            }
            if(root->left)   q.push({root->left, p-1});
            if(root->right)  q.push({root->right, p+1});
        }
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        int m = 0;
        dfs(root, 0, m);
        vector<vector<int>> ans(m);
        bfs(root, m, ans);
        return ans;
        
    }
};