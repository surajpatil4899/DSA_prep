class Solution {
public:
    
    bool isok(int row,int col,vector<string> &board,int n){
        int dr = row;
        int dc = col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        
        row = dr;
        col = dc;
        while(col>=0){
           if(board[row][col]=='Q') return false;
            col--;
        }
        
        row = dr;
        col = dc;
        while(col>=0 && row<n){
           if(board[row][col]=='Q') return false; 
            col--;
            row++;
        }
        
        return true;
    }
    
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n){

          if(col == n) {
            ans.push_back(board); 
            return; 
        }
    
        for(int row = 0;row<n;row++) {
            if(isok(row, col, board, n)) {
                board[row][col] = 'Q'; 
                solve(col+1, board, ans, n); 
                board[row][col] = '.'; 
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        
        solve(0,board,ans,n);
        
        return ans;
    }
};