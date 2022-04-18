#include <bits/stdc++.h>
using namespace std;
const int N = 30005;
int dp[N][600];
int a[N];
int n,d;
int rec(int cur, int off){
    if(cur>=N) return 0;
    
     int &ret = dp[cur][300 + off];
  if(ret != -1)
    return ret;
  ret = 0;

  if(cur + d + off - 1 > cur)
    ret = max(ret, rec(cur + (d + off - 1), off - 1) + a[cur]);
  ret = max(ret, rec(cur + d + off, off) + a[cur]);
  ret = max(ret, rec(cur + (d + off + 1), off + 1) + a[cur]);

  return ret;
}
int main() {
    memset(dp, -1, sizeof(dp));
    cin>>n>>d;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    cout<<rec(d,0)<<endl;
	return 0;
}
