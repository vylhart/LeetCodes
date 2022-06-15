class Solution {
public:
    int binarySearch(int s, vector<int> &p, long long success){
        int l=0, h=p.size()-1;
        int ans=-1;
        while(l<=h){
            int m = l+(h-l)/2;
            if((long long)s*p[m] >= success){
                l=m+1;
                ans=m;
            }
            else{
                h=m-1;
            }
        }
        return ans+1;
    }
    
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        sort(p.rbegin(), p.rend());
        vector<int> ans;
        for(int i: s){
            int j = binarySearch(i, p, success);
            ans.push_back(j);
        }
        return ans;
        
    }
};