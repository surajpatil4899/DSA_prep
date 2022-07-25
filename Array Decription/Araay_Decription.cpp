#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int solve(vector<int>& arr,int n,int m){
	int dp[n+2][m+2];
	memset(dp, 0, sizeof(dp));

    for(int i=1;i<=n;i++){
    	for(int x=1;x<=m;x++){
    		if(i==1){
                if(arr[i]==0 || arr[i]==x) dp[i][x] = 1;
                else dp[i][x] = 0;
    		}else{
    			if(arr[i]==0 || arr[i]==x)
    				dp[i][x] = ((dp[i-1][x-1] + dp[i-1][x])%mod + dp[i-1][x+1]) % mod;
    			else
    				dp[i][x] = 0;
    		}
    	}
    }

	int ans = 0;
	for(int x=1;x<=m;x++)
		ans = (ans + dp[n][x])%mod;

	return ans;
}

int main(){
	int n,m;
	cin>>n>>m;

     vector<int> arr(n+1);
     for(int i=1;i<=n;i++)cin>>arr[i];

     	cout<<solve(arr,n,m);

}