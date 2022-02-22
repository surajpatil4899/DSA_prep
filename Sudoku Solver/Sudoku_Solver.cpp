class Solution {
public:
    
    bool solve(vector<vector<char>>& board,int n){

          for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(isok(board, i, j,n, c)){
                            board[i][j] = c; 
                            
                            if(solve(board,n))
                                return true; 
                            else
                                board[i][j] = '.'; 
                        }
                    }
                    
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isok(vector<vector<char>>& board,int i,int j,int n,char num){
        for(int k=0;k<n;k++){
            if(board[i][k]==num) return false; //for colum checking
            if(board[k][j]==num) return false;
        }
        
        //check for square
        int s = sqrt(n);
        int startrow = i - i%s;
        int startcol = j - j%s;
        
        for(int r=startrow;r<startrow+s;r++){
            for(int c=startcol;c<startcol+s;c++){
                if(board[r][c]==num) return false;
            }
        }
        
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solve(board,n);
    }
};