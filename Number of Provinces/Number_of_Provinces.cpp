class Solution {
public:
    
    void dfs(vector<vector<int>> &g,vector<bool> &visited,int vertex){
        
        if(visited[vertex]) return;
        visited[vertex] = true;
        
        for(int i=0;i<g.size();i++){
            if(g[vertex][i])
            dfs(g,visited,i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(isConnected,visited,i);
                ans++;
            }
        }
        
      return ans;  
    }
};