class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        stack<int> s;
        vector<int> minv(n, 0);
        minv[0] = nums[0];
        for(int i=1; i<n; i++){
            minv[i] = min(minv[i-1], nums[i]);
        }
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && s.top()<=minv[i]){
                s.pop();
            }
            if(!s.empty() && s.top()>minv[i] && s.top()<nums[i]){
                return 1;
            }
            if(s.empty() || s.top()>nums[i])
                s.push(nums[i]);
        }
        return 0;
    }
};

/*
3 5 0 3 4
3 3 0 0 0

4 3 
*/