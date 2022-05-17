class Solution {
public:  
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> g(n);
        int k=0;
        for(auto i : edges){
            g[i[0]].push_back({i[1], succProb[k]});
            g[i[1]].push_back({i[0], succProb[k]});
            k++;
        }
        vector<double> prob(n,0);
        queue<pair<int, double>> q;
        q.push({start, 1});
        while(!q.empty()){
            int i = q.front().first;
            double p = q.front().second;
            q.pop();
            for(auto j: g[i]){
                if(prob[j.first]<p*j.second){
                    prob[j.first]=p*j.second;
                    q.push({j.first, prob[j.first]});
                }
            }
        }
        
        
        
        return prob[end];
    }
};