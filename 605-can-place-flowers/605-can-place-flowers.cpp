class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) {
        int m = bed.size();
        bool prev = false;
        for(int i=0; i<m; i++){
            if(bed[i]==0){
                if(!prev){
                    if(i+1==m || bed[i+1]==0){
                        n--;
                        prev = 1;
                    }
                    else
                        prev = 0;
                }
                else
                    prev = 0;
            }
            else{
                prev = 1;
            }

        }
        return n<=0;
    }
};