class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> copy(arr);
        sort(copy.rbegin(), copy.rend());
        vector<int> ans;
        auto end = arr.end();
        for(int i: copy){
            auto j = find(arr.begin(), arr.end(), i);
            ans.push_back(j+1-arr.begin());
            reverse(arr.begin(), j+1);
            ans.push_back(end-arr.begin());
            reverse(arr.begin(), end);
            //cout<<*end;
            end--;
            //break;
        }
        return ans;
    }
};