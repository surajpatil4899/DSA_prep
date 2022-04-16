#include <bits/stdc++.h>
using namespace std;
int n = 2e5 + 5, m;
vector<vector<int>> adj(n);
vector<int> vis(n);
bool isCycle;
void dfs(int u){
    vis[u] = 1;
    if(adj[u].size() != 2) isCycle = false;
    for(int v:adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
int main() {
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
           isCycle = true;
           dfs(i);
           if(isCycle) ans++;
        }
    }
    
    cout<<ans<<endl;
	
	return 0;
}
