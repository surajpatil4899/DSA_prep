#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> g[200001];
ll sa[200001];
ll ans[200001];
int subsize[200001];
int total;

void evaluate(int src,int par){
    int node = 1;
    ll ans = 0;
    for(auto child:g[src]){
        if(child != par){
        evaluate(child,src);
        node += subsize[child];
        ans += subsize[child] + sa[child];
      }
    }
    
    sa[src] = ans;
    subsize[src] = node;
}

void solve(int src,int par,ll par_ans){
   ans[src] = sa[src] + (par_ans + (total - subsize[src]));
    for(auto child:g[src]){
        if(child==par) continue;
        solve(child,src,ans[src] - (sa[child] + subsize[child]));
    }
    
  
}

int main() {

   int n;
   cin>>n;
   total = n;
   for(int i=1;i<n;i++){
       int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
   }
  evaluate(1,0);
  solve(1,0,0);
  
  for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
