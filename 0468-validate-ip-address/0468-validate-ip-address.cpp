class Solution {
public:
    bool checkIPv4(string ip){
        
        ip+= '.';
        int x = 0;
        string y = "";
        int cnt = 0;
        for(char c: ip){
            if(c=='.'){
                cnt++;
                if(x>=0 && x<=255 && y==to_string(x)){
                    y = "";
                    x = 0;
                }
                else
                    return 0;
            }
            else if(c>='0' && c<='9'){
                x = x*10 + (c-'0');
                y += c;
            }
            else{
                return 0;
            }
            if(x>255)   return 0;
        }
        return cnt == 4;
        
    }
    
    bool checkIPv6(string ip){
        ip+= ':';
        int x = 0;
        int cnt = 0;
        for(char c: ip){
            if(c==':'){
                cnt++;
                if(x>=1 && x<=4)
                    x = 0;
                else
                    return 0;
            }
            else if(c>='0' && c<='9'){
                x++;
            }
            else if(c>='a' && c<='f'){
                x++;
            }
            else if(c>='A' && c<='F'){
                x++;
            }
            else{
                return 0;
            }
            if(x>4) return 0;
        }
        return cnt == 8;
        
    }
    
    
    string validIPAddress(string queryIP) {
        if(checkIPv4(queryIP)){
            return "IPv4";
        }
        else if(checkIPv6(queryIP)){
            return "IPv6";
        }
        return "Neither";
    }
};