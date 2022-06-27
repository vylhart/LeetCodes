class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //nums2.push_back(-1);
        stack<int> s;
        unordered_map<int, int> map;
        for(int i: nums2){
            while(!s.empty() && i>s.top()){
                map[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        vector<int> v;
        for(int i: nums1){
            if(map.find(i)==map.end()){
                v.push_back(-1);
            }
            else{
                v.push_back(map[i]);
            }
        }
        return v;
    }
};