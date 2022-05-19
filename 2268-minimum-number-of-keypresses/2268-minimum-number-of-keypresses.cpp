class Solution {
public:
    int minimumKeypresses(string s) {
        unordered_map<char, int> map;
        for(char c:s)   map[c]++;
        vector<pair<int,char>> v;
        for(auto i:map)   v.push_back({-i.second,i.first});
        sort(v.begin(), v.end());
        int ans=0;
        for(int i=0; i<v.size(); i++){
            ans -= v[i].first * (1+i/9); 
            //cout<<;
        }
        return ans;
    }
};