class Solution {
public:
  int dp[201][201];
    int solve(vector<vector<int>>& grid,int i,int j){
        if(i==0 && j==0) return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int m = INT_MAX;
        if(i>0){
            m = grid[i][j] + solve(grid,i-1,j);
        }if(j>0){
            int s = grid[i][j] + solve(grid,i,j-1);
            m = min(m,s);
        }
        
        return dp[i][j] = m;
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        
        int i = grid.size()-1;
        int j = grid[0].size()-1;
        return solve(grid,i,j);
    }
};