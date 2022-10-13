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
    vector<TreeNode*> find(int start, int end){
        if(start>end){
            return {0};
        }
        vector<TreeNode*> left, right, curr;
        for(int i=start; i<=end; i++){
            left = find(start, i-1);
            right = find(i+1, end);
            for(auto l: left){
                for(auto r: right){
                    TreeNode* tmp = new TreeNode(i);
                    tmp -> left = l;
                    tmp -> right= r;
                    curr.push_back(tmp);
                }
            }
        }
        return curr;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return find(1, n);
    }
};