class Solution {
public:
    long long minimumMoney(vector<vector<int>>& tr) {
        long long ans = 0;
        int pos = 0;
        int neg = 0;
        for(auto i: tr){
            ans += max(0, i[0]-i[1]);
            if(i[0]>i[1]){
                pos = min(pos, -i[1]);
            }
            else{
                neg = max(neg, i[0]);
            }
        }
        return ans+max(-pos,neg);
    }
};