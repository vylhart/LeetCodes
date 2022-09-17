class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int,int> map;
        for(int i=0; i<m; i++){
            map[mat[0][i]]=1;
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(map.find(mat[i][j])!=map.end()){
                    map[mat[i][j]]++;
                }
            }
        }
        int ans = INT_MAX;
        for(auto i: map){
            if(i.second==n){
                ans = min(ans, i.first);
            }
        }
        return ans==INT_MAX? -1:ans;
    }
};