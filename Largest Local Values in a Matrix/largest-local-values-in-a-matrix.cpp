class Solution {
public:
    
    int solve(int i,int j, vector<vector<int>>& g){
        int ans = INT_MIN;
       for(int k=i;k<i+3;k++){
           for(int l=j;l<j+3;l++){
               ans = max(ans, g[k][l]);
           }
       }
        
        return ans;
    }
    
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2));
        
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                ans[i][j] = solve(i,j,grid);
            }
        }
        
        
        return ans;
    }
};