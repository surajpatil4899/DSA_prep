class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<vector<int>> &g,vector<int> &path,int v){
        path.push_back(v);
        if(v==g.size()-1) result.push_back(path);
        else{
            for(int child:g[v]) dfs(g,path,child);
        }
        
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(graph,path,0);
        
        return result;
    }
};