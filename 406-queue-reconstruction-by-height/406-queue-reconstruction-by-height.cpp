class Solution {
    int n;
    vector<int> BIT;
public:
    static bool compare(vector<int> &p1, vector<int> &p2){
        return p1[0]==p2[0] ? p1[1]>p2[1] : p1[0]<p2[0];
    }
    
    void update(int i, int x){
        for(;i<=n; i+=i&-i){
            BIT[i]+=x;
        }
    }
    
    int get(int i){
        int ans = 0;
        for(;i>0;i-=i&-i){
            ans += BIT[i];
        }
        return ans;
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compare);
        n = people.size();
        BIT.resize(n+1,0);
        vector<vector<int>> ans(n);
        for(int i=1; i<=n; i++) update(i,1);
        int l,h,p,m,pos;
        for(auto x: people){
            l=1; h=n;
            p=0;
            while(l<=h){
                m = (l+h)/2;
                pos = get(m-1);
                if(pos<=x[1]){
                    l = m+1;
                    p = m;
                }
                else{
                    h = m-1;
                }
            }
            ans[p-1]=x;
            update(p,-1);
        }
        return ans;
    }
};