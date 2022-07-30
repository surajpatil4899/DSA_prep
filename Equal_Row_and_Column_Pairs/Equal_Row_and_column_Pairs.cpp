class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for(int i=0;i<n;i++){
             
             vector<int> curr = grid[i];
            for(int j=0;j<n;j++){
                 bool flag = true;
                int ind = 0;
               for(int k=0;k<n;k++){
                   if(grid[k][j] != curr[ind]){
                      flag = false;
                       break;
                   }else ind++;
               }
                if(flag) ans++;
            }
        }
        
        return ans;
    }
};