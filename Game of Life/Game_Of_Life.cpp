class Solution {
public:
    int pos[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,1},{1,0},{1,-1}};
void gameOfLife(vector<vector<int>>& board) {
	int n = board.size(), m = board[0].size();
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			int num = 0;
			for(int k=0;k<8;k++)
			{
				int x = i + pos[k][0], y = j + pos[k][1];
				if(x>=0 && x<n && y>=0 && y<m)
				{
					if(k<4 && board[x][y]/2==1) num++;
					if(k>=4 && board[x][y]==1) num++;
				}
			}     
			if(board[i][j]==1)
			{
				if(num<2 || num>3) board[i][j] = 2;//board[i][j]*2 + 0;
				else board[i][j] = 3;//board[i][j]*2 + 1;
			}
			else
			{
				if(num==3) board[i][j] = 1;//board[i][j]*2 + 1; 
			}
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			board[i][j] = board[i][j]%2;
  }
};