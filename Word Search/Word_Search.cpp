class Solution {
    
    bool dfs(int i, int j, int index,vector<vector<char>>& board,vector<vector<bool>> &visited,string &word ){
        if(index==word.size()){return true;}
        int n = board.size();
        int m = board[0].size();
        if(i < 0 || j < 0 ) return false;
        if(i >=n || j >= m) return false;
        
        if(visited[i][j]) return false;      // check visited
        
        if(board[i][j] != word[index]) return false;  // char in string equals to board
        
        visited[i][j] = true;                   // mark visited
        
        
      if(dfs(i-1,j,index+1,board,visited,word)) return true;
      if(dfs(i+1,j,index+1,board,visited,word)) return true;
      if(dfs(i,j-1,index+1,board,visited,word)) return true;
      if(dfs(i,j+1,index+1,board,visited,word)) return true;
        
        visited[i][j] = false; //backtrack
        
        return false;  // if anyone doesnt find char return false
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j] == word[0]) {
                    if(dfs(i,j,0,board,visited,word)){
                        return true;
                      
                    }
                                    
                }
            }
        }
        
        return false;
    }
};