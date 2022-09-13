class Solution {
    int pad;
    int size;
    vector<int> BIT;
public:
    
    void update(int i){
        for(;i<size; i+=i&-i){
            BIT[i]+=1;
        }
    }
    
    int query(int i){
        int sum=0;
        for(;i>0;i-=i&-i){
            sum+=BIT[i];
        }
        return sum;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int _min = INT_MAX, _max = INT_MIN;
        for(int i: nums){
            _min = min(_min, i);
            _max = max(_max, i);
        }
        
        pad = -_min + 1;
        size= _max+pad+9;
        BIT.resize(size, 0);
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i=n-1; i>=0; i--){
            ans[i] = query(nums[i]+pad-1);
            update(nums[i]+pad);
        }
        return ans;
    }
};