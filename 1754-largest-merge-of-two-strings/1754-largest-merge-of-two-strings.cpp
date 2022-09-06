class Solution {
public:
    string largestMerge(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        string ans = "";
        int i=0, j=0;
        while(i<n || j<m){
            if(i<n && (j==m || word1.substr(i)>=word2.substr(j))){
                ans += word1[i++];
            }
            else{
                ans += word2[j++];
            }
        }
        return ans;
    }
};