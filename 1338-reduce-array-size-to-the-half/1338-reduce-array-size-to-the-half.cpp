class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> map;
        for(int i: arr) map[i]++;
        vector<pair<int,int>> v;
        for(auto i: map){
            v.push_back({-i.second, i.first});
        }
        sort(v.begin(), v.end());
        int size=0, count=0;
        for(auto i: v){
            if(size>=arr.size()/2){
                break;
            }
            size-= i.first;
            count++;
        }
        return count;
    }
};