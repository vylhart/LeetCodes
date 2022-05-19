class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans=0, prev=points[0][0];
        for(int i=1; i<points.size(); i++){
            ans = max(ans, points[i][0]-prev);
            prev = points[i][0];
        }
        return ans;
    }
};