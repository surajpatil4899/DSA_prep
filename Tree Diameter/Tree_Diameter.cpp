#include <bits/stdc++.h>
using namespace std;

vector<int> g[200001];
int dp[200001];
int diameter[200001];

void evaluate(int src,int par){
    int path = 0;
    bool leaf = 1;
    for(auto child:g[src]){
        if(child != par){
            leaf = 0;
        evaluate(child,src);
        path = max(path, dp[child]);
      }
    }
    
    if(leaf) dp[src] = 0;
    else dp[src] = 1 + path;
}

void solve(int src,int par){
    int ans = 0;
    vector<int> cdp;
    for(auto child:g[src]){
        if(par != child){
            solve(child,src);
            cdp.push_back(dp[child]);
            ans = max(ans, diameter[child]);
        }
    }
    
    int n = cdp.size();
    sort(cdp.begin(), cdp.end());
    
    if(n==0) diameter[src] = 0;
    else if(n==1) diameter[src] = 1 + cdp[0];
    else diameter[src] = 2 + cdp[n-1] + cdp[n-2];
    
    diameter[src] = max(diameter[src], ans);
}

int main() {

   int n;
   cin>>n;
   for(int i=1;i<n;i++){
       int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
   }
  evaluate(1,0);
  solve(1,0);
  cout<<diameter[1];
}
