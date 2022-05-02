class Solution {
public:
    vector<int> v;
    int sum;
    Solution(vector<int>& w) {
        sum=0;
        for(int i:w){
            sum+=i;
            v.push_back(sum);
        }
        cout<<sum<<endl;
    }
    
    int pickIndex() {
        int x = rand()%sum;
        int i = upper_bound(v.begin(), v.end(), x) - v.begin();
        return i;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */