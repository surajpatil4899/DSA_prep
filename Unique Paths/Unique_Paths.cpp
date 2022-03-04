class Solution {
public:
    int dfs(int i,int j,vector<vector<int>> &vis,int m,int n){
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(vis[i][j]) return vis[i][j];                          
        return vis[i][j] = dfs( i+1, j,vis,m,n) + dfs(i, j+1,vis,m,n);  
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> vis(m, vector<int> (n, 0));
        return dfs(0,0,vis,m,n);
    }
};