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
    int find(TreeNode* root, vector<int> sum, int t){
        if(!root)   return 0;
        sum.push_back(0);
        int ans=0;
        for(int i=0; i<sum.size(); i++){
            sum[i]+= root->val;
            if(sum[i]==t)   ans++;
        }
        ans += find(root->left, sum, t)+find(root->right, sum, t);
        return ans;
    }
    
    int pathSum(TreeNode* root, int sum) {
        vector<int> vsum;
        return find(root, vsum, sum);
    }
};