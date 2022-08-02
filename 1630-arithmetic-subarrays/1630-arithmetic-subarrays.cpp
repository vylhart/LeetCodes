class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> ans;
        for(int i=0; i<m; i++){
            if(r[i]-l[i]<=1){
                ans.push_back(1);
                continue;
            }
            vector<int> tmp;
            for(int j=l[i]; j<=r[i]; j++)   tmp.push_back(nums[j]);
            sort(tmp.begin(), tmp.end());
            int d = tmp[1] - tmp[0];
            bool wrong = 0;
            for(int j=1; j<tmp.size(); j++)  if(tmp[j]-tmp[j-1]!=d){
                wrong =1;
                break;
            }
            ans.push_back(!wrong);
        }
        return ans;
    }
    
};