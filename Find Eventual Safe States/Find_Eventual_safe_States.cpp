class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int> &vis,int v){
        if(vis[v]==1) return true;
        if(vis[v]==2) return false;
        
        vis[v] = 1;
        for(int child: graph[v]){
            if(dfs(graph,vis,child)) return true;
        }
        
        vis[v] = 2;
        return false;       
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> ans;
        for(int i=0;i<n;i++){
                if(!dfs(graph,vis,i)) ans.push_back(i);
        }
        
        return ans;
    }
};