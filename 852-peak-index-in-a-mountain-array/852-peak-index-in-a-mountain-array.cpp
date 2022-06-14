class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n==1)    return 0;
        int l=0, h = n-1;
        while(l<=h){
            int m = l + (h-l)/2;
            if(m==0 || arr[m-1]<arr[m]){
                if(arr[m]<arr[m+1]){
                    l = m+1;
                }
                else{
                    return m;
                }
            }
            else if(m==n-1 || arr[m]>arr[m+1]){
                if(arr[m-1]>arr[m]){
                    h = m-1;
                }
                else{
                    return m;
                }
            }            
        }
        return -1;
    }
};