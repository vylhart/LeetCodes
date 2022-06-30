class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int sum = 0;
        for(int i: piles)   sum+=i;
        return sum%2;
    }
};