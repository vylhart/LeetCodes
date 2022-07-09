class Solution {
    vector<int> v;
public:
    int find(){
        int giver = -1;
        for(int i=0; i<12; i++){
            if(v[i]!=0){
                giver = i; break;
            }
        }
        if(giver==-1)   return 0;      
        
        int ans = 100;
        int money = v[giver];
        v[giver] = 0;
        for(int i=0; i<12; i++){
            if(v[i]!=0 && v[i]*money<0){
                v[i]+= money;
                int x = find();
                //cout<<giver<<" "<<money<<" "<<x<<" "<<i<<endl;
                ans = min(ans, x);
                v[i]-= money;
            }
        }
        v[giver] = money;
        return ans+1;
    }
    
    int minTransfers(vector<vector<int>>& tran) {
        int n = tran.size();
        v.resize(12);
        for(auto &i: tran){
            v[i[0]] -= i[2];
            v[i[1]] += i[2];
        }
        return find();
        
    }
};


/*
0 -10 +5   -5
1 +10      10
2  -5      -5
*/