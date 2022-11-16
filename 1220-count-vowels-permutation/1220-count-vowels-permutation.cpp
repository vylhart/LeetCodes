class Solution {
    
public:
    
    int countVowelPermutation(int n) {
        int a,e,i,o,u;
        int mod = (int)1e9+7;
        int _a=1, _e=1, _i=1, _o=1, _u=1;
        for(int k=1; k<n; k++){
            a = _e;
            e = (_a + _i)%mod;
            i = (((_a + _e)%mod + _o)%mod + _u)%mod;
            o = (_i + _u)%mod;
            u = _a;
            
            _a = a;
            _e = e;
            _i = i;
            _o = o;
            _u = u;
            //cout<<_a<< _e<< _i<< _o<< _u<<endl;
            
        }
        return ((((_a + _e)%mod + _o)%mod + _u)%mod + _i)%mod;
    }
};