class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq, uniq;
        for(int i: arr) freq[i]++;
        for(auto i:freq){
            if(uniq.find(i.second)==uniq.end()){
                uniq[i.second]++;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
};