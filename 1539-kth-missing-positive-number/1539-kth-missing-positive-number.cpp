class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0, h=arr.size()-1;
        int ans = k;
        while(l<=h){
            int m = l + (h-l)/2;
            if(arr[m]-m-1<k){
                ans = arr[m]+ k-(arr[m]-m-1);
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
        return ans;
    }
};