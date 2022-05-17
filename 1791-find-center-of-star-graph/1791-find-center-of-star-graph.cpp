class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int u = edges[0][0], v= edges[0][1];
        int x = edges[1][0], y= edges[1][1];
        if(x==u || x==v)    return x;
        return y;
    }
};