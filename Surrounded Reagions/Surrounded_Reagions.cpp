class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j){
         if(grid[i][j] == 'O'){
        
        grid[i][j] = '1';

        if(i+1 < grid.size()) dfs(grid, i+1, j);
        if(i > 1) dfs(grid, i-1, j);
        if(j+1 < grid[i].size()) dfs(grid, i, j+1);
        if(j > 1) dfs(grid, i, j-1);
      }
    }
    void solve(vector<vector<char>>& board) {
        if(board.size()==0) return;
        int n = board.size(), m = board[0].size();
       
        for(int i=0;i<n;i++){
           dfs(board,i,0);
            dfs(board,i,m-1);
        }
        
        for(int j=0;j<m-1;j++){
            dfs(board,0,j);
            dfs(board,n-1,j);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j] = 'X';
                else if(board[i][j]=='1') board[i][j] = 'O';
                
            }
        }
    }
};