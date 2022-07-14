// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends

int count(int mat[MAX][MAX], int v, int n){
    int j = n-1;
    int ans = 0;
    for(int i=0; j>=0 && i<n; i++){
        while(j>=0 && mat[i][j]>v){
            j--;
        }
        ans += j+1;
    }
    return ans;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int l = mat[0][0];
    int h = mat[n-1][n-1];
    int ans = -1;
    while(l<=h){
        int m = l+ (h-l)/2;
        int x = count(mat, m , n);
        if(x>=k){
            ans = m;
            h = m-1;
        }
        else{
            l = m+1;
        }
    }
    return ans;
}
