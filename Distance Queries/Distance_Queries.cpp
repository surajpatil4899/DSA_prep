#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> tree[200001];
int up[200001][20];
int level[200001];
 
 void dfs(int src,int par,int lvl){
     level[src] = lvl;
     for(int child:tree[src]){
         if(child != par){
             dfs(child,src,lvl+1);
         }
     }
 }
 
void binary_lifting(int src, int par)
{
    up[src][0] = par;
    for(int i = 1; i < 20; i++)
    {
        if(up[src][i-1] != -1)
            up[src][i] = up[up[src][i-1]][i-1];
        else up[src][i] = -1;
    }
 
    for(int child : tree[src])
    {
        if(child != par)
            binary_lifting(child, src);
    }
}
 
int lift_node(int node, int jump_required)
{
    if(node == -1 || jump_required == 0)
        return node;
 
    for(int i = 19; i >= 0; i--){
        if(jump_required >= (1<<i)){
            return lift_node(up[node][i], jump_required - (1<<i));
        }
    }
}

int lca(int u,int v){
    if(level[u] < level[v]) swap(u,v);
    u = lift_node(u, level[u] - level[v]);
    if(u==v) return u;
    
    for(int i=19;i>=0;i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    
    return lift_node(u,1);
}
 
int main() {

   ll t,n,m,x,i,j,k,q,u,v;
   //cin >> t;
  
        cin >> n >> q;
        for(int i=1;i<n;i++)
        {
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        binary_lifting(1, -1);
        dfs(1,0,0);
        while(q--){
            cin >>u>>v;
            int x = lca(u,v);
            int ans = (level[u] - level[x]) + (level[v] - level[x]);
            cout << ans << '\n';
        }

   return 0;
}