class Solution {
public:
    int dp[301];
    bool solve(string s,int pos,vector<string> &word){
        if(pos==s.size()) return true;
        
        if(dp[pos] != -1) return dp[pos];
        
        for(int i=pos;i<s.size();i++){
            string w = s.substr(pos,i-pos+1);
            if(find(word.begin(), word.end(),w) != word.end()){
                if(solve(s,i+1,word)) return dp[pos] = true;
            }
        }
        
        return dp[pos] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        return solve(s,0,wordDict);
    }
};