class Solution {
public:
    
    void dfs(int v,int& count,vector<int> g[],vector<int>& vis){
         if(vis[v]) return;
         count++;
         vis[v] = 1;
        for(auto child:g[v]){
              dfs(child,count,g,vis);    
        }

    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& r) {
        
        vector<int> g[n];
        
        for(auto it:edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n, 0);
        for(int i=0;i<r.size();i++)vis[r[i]] = 1;
        
        int count = 0;
         dfs(0,count,g,vis);
        
        return count;
    }
};