class Solution {
public:
    bool bipartite(vector<vector<int>>& g,vector<int> &color,int vertex){
                
        for(int child: g[vertex]){
            if(color[child]==-1){
            color[child] = !color[vertex];
            if(!bipartite(g,color,child)) return false;
            }
            else if(color[child]==color[vertex]) return false;
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i] = 1;
                if(!bipartite(graph,color,i)) return false;
            }
        }
        
        return true;
    }
};