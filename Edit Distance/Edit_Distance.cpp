#include <bits/stdc++.h>
using namespace std;

 
int dp[5001][5001];
 
 int solve(string &s1,string &s2,int i,int j){
      if(i==0) return j;
      if(j==0) return i;
      
      if(dp[i][j] != -1) return dp[i][j];
      
      if(s1[i-1]==s2[j-1])
       return dp[i][j] = solve(s1,s2,i-1,j-1);
       
       return dp[i][j] = 1 + min(solve(s1,s2,i,j-1), min(solve(s1,s2,i-1,j),
       solve(s1,s2,i-1,j-1)));
  }
 
int main(){

    int t=1;
    // cin>>t;
    memset(dp, -1 , sizeof(dp));
    
    while(t--){
    	string s1,s2;
    	cin>>s1>>s2;
       cout << solve(s1,s2,s1.size(),s2.size());     
    }
    return 0;
}