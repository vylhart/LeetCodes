class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> map;
        for(int i: arr){
            if(i==0 && map[i])   return 1;
            else if((i%2==0 && map[i/2]) || map[i*2])   return 1;
            map[i]++;
        }
        return 0;
        
    }
};