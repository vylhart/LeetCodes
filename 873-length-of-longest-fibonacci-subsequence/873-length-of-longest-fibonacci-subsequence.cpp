class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> map;
        for(int i: arr){
            map[i]=1;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long a = arr[i];
                long b = arr[j];
                int tmp = 2;
                long c = a+b;
                while(map.find(c)!=map.end()){
                    tmp++;
                    a = b;
                    b = c;
                    c = a+b;
                }
                ans = max(ans, tmp);
            }
        }
        return ans<3? 0:ans;
    }
};