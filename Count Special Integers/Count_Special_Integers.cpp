class Solution {
public:
    int dp[11][2][1024];
    int solve(string& s,int tight,int pos,int mask){
        if(pos==s.size()){
            return mask != 0;
        }
        
        if(dp[pos][tight][mask] != -1) return dp[pos][tight][mask];
        
        int ans = 0;
        if(tight){
           
            for(int i=0;i<=s[pos] - '0';i++){
                
                if(mask & (1<<i)) continue;
                
                int newMask = (mask == 0 && i == 0 ? mask : (mask | (1<<i)));
                
                if(i == s[pos]- '0')
                  ans += solve(s,1,pos+1,newMask);
                else ans += solve(s,0,pos+1,newMask);
            }
            
        }else{
            for(int i=0;i<=9;i++){
                
                if(mask & (1<<i)) continue;
                
                int newMask = (mask == 0 && i == 0 ? mask : (mask | (1<<i)));
                
                ans += solve(s,0,pos+1,newMask);
                
            }
        }
        
        return dp[pos][tight][mask] = ans;
    }
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        
        return solve(s,1,0,0);
    }
};