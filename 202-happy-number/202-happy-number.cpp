class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> map;
        while(map.find(n)==map.end()){
            map[n]=1;
            if(n==1)    return 1;
            int x = n;
            n = 0;
            while(x){
                n += (x%10)*(x%10);
                x /= 10;
            }
        }
        return 0;
    }
};