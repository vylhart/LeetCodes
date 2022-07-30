class Solution {
public:
    
    bool dfs(int i, vector<vector<int>> &graph, vector<int> &vis, stack<int> &s){
        if(vis[i]==2)   return 1;
        vis[i]=1;
        for(int j: graph[i]){
            if(vis[j]==1)   return false;
            if(!dfs(j, graph, vis, s)) return false;
        }
        vis[i]=2;
        s.push(i);
        return 1;
    }
    
    string alienOrder(vector<string>& words) {
        vector<vector<int>> graph(26);
        int n = words.size();
        unordered_map<int, int> map;
        for(int i=0; i<n; i++)  for(int j=0; j<words[i].length(); j++)   map[words[i][j]-'a']++;
        for(int i=0; i<n-1; i++){
            int j=0;
            while(j<min(words[i].length(), words[i+1].length()) && words[i][j]==words[i+1][j]){
                j++;
            }
            if(j==min(words[i].length(), words[i+1].length())){
                if(words[i].length() > words[i+1].length()){
                    return "";
                }
            }
            if(j<min(words[i].length(), words[i+1].length())){
                graph[ words[i][j]-'a' ].push_back( words[i+1][j]-'a' );
            }
        }
        stack<int> s;
        vector<int> vis(26, 0);
        for(auto i: map){
            if(!dfs(i.first, graph, vis, s)){
                return "";
            }
        }
        string ans="";
        while(!s.empty()){
            char c = s.top()+'a';
            ans += c;
            s.pop();
        }
        return ans;
    }
};