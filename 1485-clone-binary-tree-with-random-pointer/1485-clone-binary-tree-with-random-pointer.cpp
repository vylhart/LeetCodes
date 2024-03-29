/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
    unordered_map<Node*, NodeCopy*> clone;
public:
    NodeCopy* dfs(Node* root){
        if(!root)   return 0;
        NodeCopy* node = new NodeCopy(root->val);
        clone[root] = node;
        node->left = dfs(root->left);
        node->right= dfs(root->right);
        return node;
    }
    
    void _dfs(Node* root){
        if(!root)   return;
        clone[root]->random = clone[root->random];
        _dfs(root->left);
        _dfs(root->right);
    }
    
    NodeCopy* copyRandomBinaryTree(Node* root) {
        NodeCopy* node = dfs(root);
        _dfs(root);
        return node;
    }
};