class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> map;
        for(auto &i: paths){
            map[i[0]]++;
        }
        for(auto &i: paths){
            if(map[i[1]]<1){
                return i[1];
            }
        }
        return "";
    }
};