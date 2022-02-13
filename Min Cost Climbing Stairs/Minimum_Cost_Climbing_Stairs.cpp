class Solution {
public:
    int dp[1005];
    
    int find(vector<int> &cost,int n){
        if(n==cost.size()-1 || n==cost.size()-2) return cost[n];
        
        if(dp[n] != -1) return dp[n];
        
        int x = find(cost,n+1);
        int y = find(cost,n+2);
        
        return dp[n] = min(x,y)+cost[n];
        
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()==2) return min(cost[0],cost[1]);
        memset(dp, -1, sizeof(dp));
        
        int x = find(cost,0);
        int y = find(cost,1);
        
        return min(x,y);
    }
};