class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        for(int i: arr1){
            if(binary_search(arr2.begin(), arr2.end(), i) && 
              binary_search(arr3.begin(), arr3.end(), i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};