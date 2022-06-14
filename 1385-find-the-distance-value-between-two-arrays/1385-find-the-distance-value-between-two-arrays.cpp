class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        for(int x: arr1){
            int i = lower_bound(arr2.begin(), arr2.end(), x-d) - arr2.begin();
            int j = upper_bound(arr2.begin(), arr2.end(), x+d) - arr2.begin();
            if(j-i==0)   ans++;
        }
        return ans;
        
    }
};