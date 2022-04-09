class Solution {
public:
    unordered_map<string, bool> vis;
    double dfs(string source, string target, unordered_map<string, vector<string>> &g, unordered_map<string,double> &map){
        if(source==target)  return 1;
        if(map[source+"/"+ target]){
                return map[source +"/"+  target];
        }
        cout<<source<<target<<" ";
        double ans = -1;
        vis[source]=1;
        for(string curr: g[source]){
            if(vis[curr]) continue;
            ans = dfs(curr, target, g, map);
            if(ans>0){
                double x = map[source+"/"+ curr] * ans;
                cout<<map[source+"/"+ curr]<<"*"<<source+"/"+ curr;
                map[source+"/"+ target] = x;
                return x;
            }
        }
        return ans;
    }
    
    vector<double> calcEquation(vector<vector<string>>& eqn, vector<double>& val, vector<vector<string>>& queries) {
        int n = val.size();
        unordered_map<string, double> map;
        unordered_map<string, double> exist;
        unordered_map<string, vector<string>> g;
        for(int i=0; i<n; i++){
            g[eqn[i][0]].push_back(eqn[i][1]);
            g[eqn[i][1]].push_back(eqn[i][0]);
            
            map[eqn[i][0] +"/"+ eqn[i][1]] = val[i];
            map[eqn[i][1] +"/"+ eqn[i][0]] = 1/val[i];
            exist[eqn[i][0]]++;
            exist[eqn[i][1]]++;
        }
        
        vector<double> ans;
        for(auto i: queries){
            if(exist[i[0]] && exist[i[1]]){
                vis.clear();
                double x = dfs(i[0], i[1], g, map);
                ans.push_back(x);
            }
            else{
                ans.push_back(-1);
            }
            //break;
            
        }
        
        return ans;
    }
};