class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> l,r;
        int n = nums.size();
        for(int i=0; i<n; i++){
            while(!l.empty() && nums[l.top()]>nums[i]){
                l.pop();
            }
            l.push(i);
        }
        while(!l.empty() && l.top()!=l.size()-1){
            l.pop();
        }
        for(int i=n-1; i>=0; i--){
            while(!r.empty() && nums[r.top()]<nums[i]){
                r.pop();
            }
            r.push(i);
        }
        while(!r.empty() && n-r.top()!=r.size()){
            r.pop();
        }
        int x = l.empty() ? 0 : l.top()+1;
        int y = r.empty() ? n-1 : r.top()-1;
        //cout<<x<<y<<endl;
        return max(y-x+1, 0);
    }
};