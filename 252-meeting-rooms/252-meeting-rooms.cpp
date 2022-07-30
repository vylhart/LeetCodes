class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prev = -1;
        for(auto &i: intervals){
            if(prev>i[0])   return 0;
            prev = i[1];
        }
        return 1;
    }
};