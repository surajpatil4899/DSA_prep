class Solution {
public:
    void dfs(int v,vector<vector<int>> &g,vector<int> &vis){
        if(vis[v]) return;
        vis[v] = true;
        for(int child:g[v]){
            dfs(child,g,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<vector<int>> g(n);
        for(auto edge: connections){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n, false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,g,vis);
                count++;
            }
        }
        
        return count - 1;
    }
};