class Solution {
    int target;
    int n;
    vector<vector<int>> ans;
    vector<int> cand;
    
public:
    void find(int i, int sum, vector<int> &v){
        if(sum==target){
            ans.push_back(v);
            return;
        }
        if(i>=n || sum>target){
            return;
        }
        
        find(i+1, sum, v);
        v.push_back(cand[i]);
        find(i, sum+cand[i], v);
        v.pop_back();       
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int _t) {
        cand = candidates;
        n = cand.size();
        target = _t;
        vector<int> tmp;
        find(0, 0, tmp);
        return ans;
    }
};