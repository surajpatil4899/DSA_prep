#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
#define ll long long
int n;
 const int mod = 1e9+7;
 
 ll solve(int i,int j,vector<vector<char>>& maze){
    if(i==n-1 && j==n-1) return 1;
    if(i>=n || j>=n) return 0;
     if(maze[i][j]=='*') return 0;
     
     if(dp[i][j] != -1) return dp[i][j];
    
    return dp[i][j] = (solve(i+1,j,maze)%mod + solve(i,j+1,maze)%mod)%mod;
    
 }

int main(){
    memset(dp, -1, sizeof(dp));
    
    cin>>n;
    vector<vector<char>> maze(n,vector<char> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
    if(maze[n-1][n-1]=='*')cout<<0;
    else
    cout<<solve(0,0,maze);
}