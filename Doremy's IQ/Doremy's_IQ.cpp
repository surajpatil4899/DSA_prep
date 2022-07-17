#include <bits/stdc++.h>
using namespace std;

#define ll long long


void solve()
{
    int n,q; cin>>n>>q;
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>c[i];
    vector<char> ans(n);
    int q1 = 0;
    for(int i=n-1;i>=0;i--){
        if(c[i]<=q1){
            ans[i] = '1';
        }else{
            if(q1<q){
                q1++;
                ans[i] = '1';
            }else{
                ans[i] = '0';
            }
        }
    }
    for(auto i:ans)cout<<i;
    cout<<endl;
}
//b

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
	return 0;
}
