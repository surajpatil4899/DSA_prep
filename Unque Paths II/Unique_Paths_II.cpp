class Solution {
public:
    int dp[101][101];
    int dfs(int i,int j,vector<vector<int>>& grid){
        
       if(i == grid.size() || j == grid[0].size() || grid[i][j] == 1)return 0; 
        
        
      if(i==grid.size()-1 && j==grid[0].size()-1){
          if(grid[i][j]) return 0;
          return 1;
      } 

        if(dp[i][j] != -1) return dp[i][j];
        
       int count = 0;

        count += dfs(i+1,j,grid);
 
        count += dfs(i,j+1,grid);
        
       return dp[i][j] = count; 
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof(dp));
        return dfs(0,0,obstacleGrid);
    }
};