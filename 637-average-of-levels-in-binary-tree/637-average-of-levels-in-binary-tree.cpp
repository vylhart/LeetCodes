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
    void dfs(TreeNode* root, vector<double> &sum, vector<int> &c, int h){
        if(!root)   return;
        if(sum.size()==h){
            sum.push_back(0);
            c.push_back(0);
        }
        sum[h]+=root->val;
        c[h]+=1;
        dfs(root->left, sum, c, h+1);
        dfs(root->right,sum, c, h+1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<int> c;
        vector<double> sum;
        dfs(root, sum, c, 0);
        for(int i=0; i<c.size(); i++){
            sum[i]/=c[i];
        }
        return sum;
    }
};