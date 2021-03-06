class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        int mod = 1e9+7;
        int ans = 0, i=0, t;
        unordered_map<int, int> map;
        for(int i=0; i<n; i++){
            t = target - arr[i];
            ans  = (ans + map[t])%mod;
            for(int j=0; j<i; j++){
                map[arr[i]+arr[j]]++;
            }
        }
        return ans;
    }
};