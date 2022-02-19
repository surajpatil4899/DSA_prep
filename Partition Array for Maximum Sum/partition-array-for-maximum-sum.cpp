class Solution {
public:
    int dp[501];
    int solve(vector<int> &a,int i,int k){
        if(i>=a.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int maxe = 0;
        int maxs = 0;
        for(int j=i;j<i+k && j<a.size();j++){
            maxe = max(maxe, a[j]);
            maxs = max(maxs, maxe * (j-i+1) + solve(a,j+1,k));
        }
        
        return dp[i] = maxs;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(arr,0,k);
        
    }
};