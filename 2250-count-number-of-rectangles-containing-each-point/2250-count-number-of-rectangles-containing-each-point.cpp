class Solution {
public:

    vector<int> countRectangles(vector<vector<int>>& r, vector<vector<int>>& p) {
        vector<vector<int>> xcord(101);
        for(auto i: r){
            xcord[i[1]].push_back(i[0]); 
        }
        for(int i=0; i<=100; i++){
            sort(xcord[i].begin(), xcord[i].end());
        }
        
        vector<int> ans;
        for(auto i: p){
            int count = 0;
            for(int ycord=i[1]; ycord<=100; ycord++){
                if(xcord[ycord].size()==0)  continue;
                int j = lower_bound(xcord[ycord].begin(), xcord[ycord].end(), i[0]) - xcord[ycord].begin();
                count+= xcord[ycord].size() - j;
            }
            ans.push_back(count);
        }
        return ans;
    }
};