class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> count(n, 0);
        for(auto &i: roads){
            count[i[0]]++;
            count[i[1]]++;
        }
        sort(count.begin(), count.end());
        long long ans = 0;
        for(int i=0; i<n; i++){
            ans += count[i]*(i+1L);
        }
        return ans;
    }
};