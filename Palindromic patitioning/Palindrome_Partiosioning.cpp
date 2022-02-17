class Solution{
public:
     int dp[501][501];
     bool isPal(string &s,int i,int j){
  
         while(i<j){
             if(s[i]!=s[j]) return false;
             else{
                 i++;
                 j--;
             }
         }
         
         return true;
     }
     int solve(string &s,int i,int j){
         if(i>=j) return 0;
         
         if(dp[i][j] != -1) return dp[i][j];
         
         if(isPal(s,i,j)==true)  return 0;
         int min = INT_MAX;
         for(int k=i;k<j;k++){
            int temp = solve(s,i,k) + solve(s,k+1,j) + 1;
            if(temp<min) min = temp;
         }
         
         return dp[i][j] = min;
     }
    int palindromicPartition(string str)
    {
        memset(dp, -1, sizeof(dp));
       return solve(str,0,str.size()-1);
    }
};
