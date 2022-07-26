#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define int long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
 
const int mod  = 1000000007;
int dp[1000001][2];
//0 both below tile are free (ek chada + ek chada + dono chade + dono band upar alag alag  + dono band upar ek )
//1 both below tile jud gaye (chade + band hogaye upar ek + band hogye upar do)
 
void fun(){
    dp[1][1] = 1;
    dp[1][0] = 1;
    for(int i=2;i<=1000001;i++){
        dp[i][0] = ((dp[i-1][0] * 4)%mod + dp[i-1][1]%mod) %mod;
        dp[i][1] = (dp[i-1][0]%mod + (2*dp[i-1][1])%mod) %mod;
    }
}
 
int32_t main(){
    fast
    int t=1;
    cin>>t;
    
    fun();
    while(t--){
        int n;cin>>n;
        cout<<(dp[n][1] + dp[n][0])%mod<<endl;
    }
    return 0;
}