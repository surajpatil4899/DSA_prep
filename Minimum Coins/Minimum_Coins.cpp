#include<bits/stdc++.h>
using namespace std;
int dp[1000001];


const int mod = 1e9+7;

   int req(vector<int> &coins,int a){
        if(a==0) return 0;
        if(a<0) return INT_MAX;
        if(dp[a] != -1) return dp[a];
        int ans = INT_MAX;
        for(int coin: coins){
                ans = min(ans+0LL, req(coins,a-coin)+1LL);
        }
        
        return dp[a] = ans;
    }

int main(){

 memset(dp, -1 , sizeof(dp));
    long long n,x;
	cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
	    cin>>coins[i];
	}
	
 
	 int ans = req(coins,x);
	 if(ans == INT_MAX) cout << -1 << endl;
	 else cout << ans << endl;
}