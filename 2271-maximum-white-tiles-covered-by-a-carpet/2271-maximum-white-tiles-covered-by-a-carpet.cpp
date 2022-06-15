class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        int n = tiles.size();
        int i=0, j=0;
        int cover = 0;
        int ans = 0;
        while(i<n && j<n){
            int end = tiles[i][0] + carpetLen - 1;
            while(j<n && tiles[j][1]<=end){
                cover += tiles[j][1] - tiles[j][0] + 1;
                j++;
            }
            int partial = j<n ? max(end - tiles[j][0] + 1, 0) : 0;
            ans = max(ans, cover+partial);
            cover -= tiles[i][1] - tiles[i][0] + 1;
            i++;
        }
        return ans;
    }
};