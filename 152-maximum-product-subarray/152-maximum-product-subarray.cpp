class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_all = -(int)1e8;
        int min_here= -max_all;
        int max_here=  max_all;
        int min_here_= -max_all;
        int max_here_=  max_all;
        /*for(int i:nums){
            min_here = min(min_here, i);
            max_here = max(max_here, i);
        }
        max_all = max_here;*/
        for(int i:nums){
            if(i<0){
                min_here_ = min(i, i*max_here);
                max_here_ = max(i, i*min_here);
            }
            else{
                min_here_ = min(i, i*min_here);
                max_here_ = max(i, i*max_here);
            }
            min_here = min_here_;
            max_here = max_here_;
            max_all = max(max_all, max_here);
        }
        
        return max_all;
    }
};