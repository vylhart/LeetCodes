class Solution {
public:
    static bool compare(vector<int> &A, vector<int> &B){
        return A[1]<B[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), compare);
        int dur = 0;
        priority_queue<int> q;
        for(auto &i: courses){
            if(dur+i[0]<=i[1]){
                dur+=i[0];
                q.push(i[0]);
            }
            else if(!q.empty() && i[0]-q.top()<0){
                dur+=i[0]-q.top();
                q.pop();
                q.push(i[0]);
            }
        }
        return q.size();
    }
};