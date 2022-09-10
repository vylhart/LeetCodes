class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        long bb=INT_MAX, b=INT_MAX, c=INT_MAX, cc=INT_MAX, sum=0;
        for(int i: nums){
            sum+= i;
            switch(i%3){
                case 1:
                    if(i<b){
                        bb = b;
                        b = i;
                    }
                    else if(i<bb){
                        bb = i;
                    }
                    break;
                case 2:
                    if(i<c){
                        cc = c;
                        c = i;
                    }
                    else if(i<cc){
                        cc = i;
                    }
                    break;
            }
        }
        int ans = sum;
        switch(sum%3){
            case 1:
                ans -= min(b, c+cc);
                break;
            case 2:
                ans -= min(c, b+bb);
                break;
        }
        return ans;
    }
};