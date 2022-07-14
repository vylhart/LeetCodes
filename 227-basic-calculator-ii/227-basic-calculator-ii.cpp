class Solution {
public:
    bool isDigit(char c){
        return c>='0' && c<='9';
    }

    int calculate(string s) {
        int n = s.length();
        stack<int> nums;
        int curr = 0;
        char oper = '+';
        
        
        for(int i=0; i<=n; i++){
            char c = i==n ? '+' : s[i];
            if(isDigit(c)){
                curr = curr*10 + (c-'0');
            }
            else if(c=='/'||c=='+'||c=='-'||c=='*'){
                if(oper=='+'){
                    nums.push(curr);
                }
                else if(oper=='-'){
                    nums.push(-curr);
                }
                else if(oper=='*'){
                    int prev = nums.top();  nums.pop();
                    nums.push(prev*curr);
                    
                }
                else if(oper=='/'){
                    int prev = nums.top(); nums.pop();
                    nums.push(prev/curr);
                }
                oper = c;
                curr = 0;
            }
        }
        int ans = 0;
        while(!nums.empty()){
            ans+= nums.top();
            nums.pop();
        }
        return ans;
    }
};