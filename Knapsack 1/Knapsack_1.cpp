#include<bits/stdc++.h>
using namespace std;
long long dp[100001][101];
int wt[105], val[105];

long long find(int W,int n){
	if(W==0 || n<=0) return 0;

      if(dp[W][n] != -1) return dp[W][n];

    if(wt[n-1] <= W)
    	return dp[W][n] = max(val[n-1] + find(W-wt[n-1],n-1), 
    		find(W, n-1));

    else if(wt[n-1]>W)
    	return dp[W][n] = find(W,n-1);

}

int main(){
	memset(dp, -1, sizeof(dp));
	int n,W;
	cin>>n>>W;
	
	for(int i=0;i<n;i++){
		cin>>wt[i]>>val[i];
	}
 
	cout<<find(W,n);
}