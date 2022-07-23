#include<bits/stdc++.h>
using namespace std;

int dp[1000001];

const int mod = 1e9+7;

long long find(int n){
	if(n==0 || n==1) return 1;
    
    if(dp[n] != -1) return dp[n];
    
    long long ans = 0;
   for(int i=1;i<=6;i++){
       if(n-i >= 0)ans += find(n-i)%mod;
   }

	    return dp[n] = ans%mod;
}

int main(){

 memset(dp, -1 , sizeof(dp));
    int n;
	cin>>n;
	
 
	cout<<find(n)<<endl;
}