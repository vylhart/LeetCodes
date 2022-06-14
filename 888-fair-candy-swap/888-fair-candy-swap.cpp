class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> map;
        int sumA = 0, sumB = 0;
        for(int i:A){
            sumA += i;
            map[i]=i;
        }
        for(int i:B) sumB+=i;
        int diff = (sumA-sumB)/2;
        for(int i:B){
            if(map[i+diff]) return {i+diff, i};
        }
        
        return {0,0};
    }
};