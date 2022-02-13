#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
int dp[N];
int jumps(int i){
	if(i==0) return 0;
	if(dp[i] != -1) return dp[i];
	int cost = INT_MAX;

	cost = min(cost, jumps(i-1) + abs(a[i] - a[i-1]));

	if(i>1)
	cost = min(cost, jumps(i-2) + abs(a[i] - a[i-2]));

	return dp[i] = cost;
}

int main(){
	memset(dp, -1, sizeof(dp));
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	 cin>>a[i];
	}

	cout<<jumps(n-1);
}