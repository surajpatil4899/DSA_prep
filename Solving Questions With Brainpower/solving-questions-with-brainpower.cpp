class Solution {
public:
    long long dp[200001];
  #define ll long long
    
    ll getPoints(int idx, vector<vector<int>>& questions, int n){
        
        if(idx == n-1) return questions[idx][0];
        if(idx >= n) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        ll select = questions[idx][0] + getPoints(idx + questions[idx][1] + 1, questions, n);
        ll ignore = 0                 + getPoints(idx + 1                    , questions, n);
        
        return dp[idx] = max(select, ignore);    
    }
    
    ll mostPoints(vector<vector<int>>& questions) {
        memset(dp, -1, sizeof(dp));
        int n = questions.size();
        return getPoints(0, questions, n);
    }
};