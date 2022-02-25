class Solution {
public:
    bool dfs(int v,vector<vector<int>>& adj,vector<int>& visited)
    {
        if(visited[v]==1)
            return true;
        if(visited[v]==2)
            return false;
        
        visited[v]=1;   //Mark current as visited
        for(int child: adj[v])
            if(dfs(child,adj,visited))
                return true;
        
        visited[v]=2;   //Mark current node as processed
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> g(numCourses, vector<int>());
        for(int i=0;i<n;i++)
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        vector<int> vis(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0 && dfs(i,g,vis)) return false;
        }
        
        return true;
    }
};