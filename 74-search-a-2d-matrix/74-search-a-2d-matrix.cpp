class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l=0, h=n*m -1;
        while(l<=h){
            int k = l+(h-l)/2;
            int i = k/m;
            int j = k%m;
            if(matrix[i][j]==target)    return 1;
            else if(matrix[i][j]<target)    l=k+1;
            else h=k-1;
        }
        return 0;
    }
};