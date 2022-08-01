class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, 1);
        for(int i=2; i*i<n; i++){
            if(prime[i]){
                for(int j=i*i; j<n; j+=i){
                    prime[j]=0;
                }
            }
        }
        int ans=0;
        for(int i=2; i<n; i++){
            if(prime[i])
            ans++;
        }
        return ans;
    }
};