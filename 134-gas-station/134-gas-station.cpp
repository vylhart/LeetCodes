class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> left;
        int n = gas.size();
        for(int i=0; i<n; i++){
            left.push_back(gas[i]-cost[i]);
        }
        for(int i=0; i<n; i++){
            left.push_back(left[i]);
        }
        int i=0, j=0;
        int sum = 0;
        bool first = true;
        while(i<n && j!=i+n && j<2*n){
            first = false;
            sum += left[j];
            while(sum<0){
                sum -= left[i];
                i++;
            }
            j++;
        }
        if(i+n==j){
            return i;
        }
        return -1;
    }
};

