class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if(n!=m)    return 0;
        int diff=0;
        unordered_map<char, int> map;
        vector<int> v;
        int same=0;
        for(int i=0; i<n; i++){
            if(s[i]!=goal[i])   v.push_back(i);
            if(map[s[i]]) same=1;
            map[s[i]]++;
        }
        diff = v.size();
        return (diff==2 && s[v[0]] == goal[v[1]] && s[v[1]] == goal[v[0]]    ) || (diff==0 && same==1);
    }
};