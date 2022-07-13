#include <bits/stdc++.h>
using namespace std;
 
vector<int> g[200001];
 
void solve(int src,int par,vector<int> &ans){
    int sub = 0;
    for(auto child:g[src]){
        if(child != par){
        solve(child,src,ans);
        sub += (1 + ans[child]);
      }
    }
    ans[src] = sub;
}
 
int main() {
 
   int n;
   cin>>n;
   for(int i=2;i<=n;i++){
       int x;
       cin>>x;
        g[x].push_back(i);
       g[i].push_back(x);
   }
   vector<int> ans(n+1);
   solve(1,0,ans);
   for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}