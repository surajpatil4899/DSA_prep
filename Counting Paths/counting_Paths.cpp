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
 
  int dfs2(int src,int par,vector<int>& pre){
     int ans = pre[src];
     for(int child:tree[src]){
         if(child != par){
           ans +=  dfs2(child,src,pre);
         }
     }
     
     pre[src] = ans;
     
     return ans;
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
        dfs(1,-1,0);
        vector<int> pre(n+1, 0);
        
        while(q--){
            cin >>u>>v;
            int x = lca(u,v);
            pre[u]+=1;
            pre[v]+=1;
            pre[x]-=1;
            
            if(up[x][0] != -1) pre[up[x][0]] -= 1;
            
        }
       dfs2(1,-1,pre);
       for(int i=1;i<=n;i++) cout<<pre[i]<<" ";
   return 0;
}