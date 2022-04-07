/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, Node* clone, unordered_map<Node*, bool> &vis, unordered_map<Node*, Node*> &map){
        if(vis[node])   return;
        vis[node]=1;
        cout<<node->val;
        map[node]=clone;
        for(Node* child: node->neighbors){
            Node* cloneChild = map[child] ? map[child] :new Node(child->val);
            clone->neighbors.push_back(cloneChild);
            dfs(child, cloneChild, vis, map);
        }      
    }
    
    Node* cloneGraph(Node* node) {
        if(!node)   return node;
        Node* clone = new Node(node->val);
        unordered_map<Node*,  bool> vis;
        unordered_map<Node*, Node*> map;
        dfs(node, clone, vis, map);
        return clone;
    }
};