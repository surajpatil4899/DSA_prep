#include<bits/stdc++.h>
using namespace std;
int dp[1000001];
#define ll long long

const int mod = 1e9+7;

   ll req(vector<int> &coins,int a){
        if(a==0) return 1;
     
        if(dp[a] != -1) return dp[a];
        ll ans = 0;
        for(int coin: coins){
            if(a-coin >= 0)
                ans += req(coins,a-coin)%mod;
        }
        
        return dp[a] = ans%mod;
    }

int main(){

 memset(dp, -1 , sizeof(dp));
    long long n,x;
	cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
	    cin>>coins[i];
	}
	
 
	 ll ans = req(coins,x);
	 
	  cout << ans << endl;
}