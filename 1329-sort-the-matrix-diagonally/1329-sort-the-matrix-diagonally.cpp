class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        int v[min(n,m)];
        for(int k=0; k<m; k++){
            int c = 0;
            for(int i=0,j=k; i<n&&j<m; i++,j++){
                v[c] = mat[i][j];c++;
            }
            sort(v, v+c);
            c=0;
            for(int i=0,j=k; i<n&&j<m; i++,j++){
                mat[i][j] = v[c];c++;
            }
        }
        for(int k=0; k<n; k++){
            int c = 0;
            for(int i=k,j=0; i<n&&j<m; i++,j++){
                v[c] = mat[i][j];c++;
            }
            sort(v, v+c);
            c=0;
            for(int i=k,j=0; i<n&&j<m; i++,j++){
                mat[i][j] = v[c];c++;
            }
        }
        return mat;
    }
};

/*
1 1 1 1
2 2 2 2
1 1 3 3
*/