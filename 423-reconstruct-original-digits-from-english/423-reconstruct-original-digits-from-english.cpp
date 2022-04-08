class Solution {
public:
    string words[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    void remove(int f[], int k, int x){

    }
    
    string originalDigits(string s) {
        
        int f[26] = {0};
        for(int i=0; i<26; i++) f[i]=0;
        for(char c:s){
            f[c-'a']++;
        }
        int ans[10]= {0};
        char key[] = {'z', 'w', 'u', 'x', 'g', 'o', 't', 'f', 's', 'i'};
        int val[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        for(int i=0; i<10; i++){
            int x = f[key[i]-'a'];
            if(x>0){
                ans[val[i]]=x;
                cout<<key[i]<<x;
                for(char c: words[val[i]]){
                    //cout<<c;
                    f[c-'a']-= x;
                 }
            }
        }
        string str = "";
        int j=0;
        for(char i='0'; i<='9'; i++){
            while(ans[j]>0){
                str+= i;
                ans[j]--;
            }
            j++;
        }
        return str;
    }
};

/*
z e r o         -> z
o n e                   -> o
t w o           -> w
t h r e e               -> t
f o u r         -> u
f i v e                 -> f
s i x           -> x
s e v e n               -> s
e i g h t       -> g
n i n e                         -> n
*/

