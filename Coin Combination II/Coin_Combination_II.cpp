#include<bits/stdc++.h>
using namespace std;
// int dp[101][1000001];
// #define ll long long

 const int mod = 1e9+7;

//   ll req(vector<int> &coins,int a,int i){
//       if(a<0 || i<0) return 0;
//         if(a==0) return 1;
     
//         if(dp[i][a] != -1) return dp[i][a];
        
//         int op1 = (coins[i]>a) ? 0 : req(coins,a-coins[i],i)%mod;
//         int op2 = (i==0) ? 0 : req(coins,a,i-1)%mod;
        
//         return dp[i][a] = (op1+op2)%mod;
//     }

int main(){
   int n,x;
  cin >> n >> x;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++)
            cin >> v[i];
        int dp[n+1][x+1];
 
        for(int i = 1; i <= n; i++)
        {
                for(int sum = 0; sum <= x; sum++)
                {
                    if(sum == 0)
                        dp[i][sum] = 1;
                    else
                    {
                        int op1 = (v[i] > sum) ? 0 : dp[i][sum - v[i]];
                        int op2 = (i == 1) ? 0 : dp[i-1][sum];
                        dp[i][sum] = (op1 + op2) % mod;
                    }
                }
        }
 
        cout << dp[n][x];
}