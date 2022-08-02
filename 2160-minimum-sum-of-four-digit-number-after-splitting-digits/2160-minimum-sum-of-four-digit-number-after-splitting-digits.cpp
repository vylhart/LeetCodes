class Solution {
public:
    int minimumSum(int num) {
        vector<int> d;
        while(num){
            d.push_back(num%10);
            num/=10;
        }
        if(d.size()%2)  d.push_back(0);
        sort(d.begin(), d.end());
        int x=0,y=0;
        for(int i=0; i<d.size(); i+=2){
            x = x*10+d[i]+d[i+1];
            y = y*10+d[i+1];
        }
        return x;
    }
};