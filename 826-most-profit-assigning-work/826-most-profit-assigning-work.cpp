class Solution {
public:
    int find(vector<pair<int,int>> &v, int w){
        int n = v.size();
        int l=0, h=n-1;
        int ans=0;
        while(l<=h){
            int m = l+(h-l)/2;
            if(v[m].first<=w){
                ans = v[m].second;
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return ans;
    }
    
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& w) {
        int n = profit.size();
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++){
            v.push_back({difficulty[i], profit[i]});
        }
        sort(v.begin(), v.end());
        sort(w.begin(), w.end());
        int ans=0;
        int j=0;
        int MAX = 0;
        for(int i=0; i<n; i++){
            MAX = max(v[i].second, MAX);
            v[i].second = MAX;
        }
        for(int i: w){
            while(j<n && v[j].first<=i){
                j++;                
            }
            if(j>0){
                ans += v[j-1].second;
            }
        }
        return ans;
    }
};