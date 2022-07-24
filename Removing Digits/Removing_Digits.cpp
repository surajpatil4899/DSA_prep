#include<bits/stdc++.h>
using namespace std;
int dp[1000001];
#define ll long long

 const int mod = 1e9+7;
 
 int solve(int n){
     if(n==0) return 0;
     
     if(dp[n] != -1) return dp[n];
     
     int maxd = -1;
     int dn = n;
     while(dn){
         maxd = max(maxd, dn%10);
         dn /= 10;
     }
     
     return dp[n] = 1 + solve(n-maxd);
 }

int main(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin>>n;
    cout<<solve(n);
}