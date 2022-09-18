class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int l[n];
        int r[n];
        for(int i=0; i<n; i++){
            int j = n-1-i;
            if(i==0) l[i]=h[i];
            else l[i] = max(h[i], l[i-1]);
            if(j==n-1) r[j]=h[j];
            else r[j] = max(h[j], r[j+1]);    
            //cout<<l[i]<<" "<<r[j]<<endl;
        }
        int ans = 0;
        for(int i=1; i<n-1; i++){
            int t = min(l[i-1], r[i+1]);
            ans +=  t>h[i] ? t-h[i] : 0;
            //cout<<t<<endl;
        }
        return ans;
    }
};
/*
****
**

***
**
*****
*/