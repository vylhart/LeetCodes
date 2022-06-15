class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(), e.end(), compare);
        vector<int> lis;
        for(auto &i: e){
            cout<<i[0]<<" "<<i[1]<<endl;
            int n = lis.size();
            if(n==0 || (lis[n-1] < i[1]))   lis.push_back(i[1]);
            else{
                int j = lower_bound(begin(lis), end(lis), i[1]) - begin(lis);
                //cout<<j<<" "<<i[1]<<endl;
                if(j!=n)
                lis[j] = i[1];
            }
        }
        cout<<endl;
        return lis.size();
    }
};

// 3 4 7 4