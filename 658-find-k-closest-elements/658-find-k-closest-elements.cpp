class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(k==arr.size())   return arr;
        int i = lower_bound(begin(arr), end(arr), x) - begin(arr);

        vector<int> ans;
        int start = i-1, end = i;
        while(end-start-1<k){
            if(end>=arr.size() || (start>=0 && abs(arr[start]-x) <= abs(arr[end]-x))){
                start--;
            }
            else{
                end++;
            }
        }
        for(int i=start+1; i<end; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};