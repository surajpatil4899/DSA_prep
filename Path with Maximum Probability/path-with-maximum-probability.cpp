class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& pro, int start, int end) {
         vector<vector<pair<int, double>>> g(n);
        for(int i=0; i<edges.size(); i++) {
            g[edges[i][0]].push_back({edges[i][1], pro[i]});
            g[edges[i][1]].push_back({edges[i][0], pro[i]});   
        }
        vector<int> vis(n, 0);
        
        priority_queue<pair<double, int>> q;
        q.push({(double)1.0, start});
        
        vector<double> dist(n, (double)0.0);
        dist[start] = 1.0;
        
        while(!q.empty()){
            auto top = q.top();
            q.pop();
           int v = top.second;
           double wt = top.first;
            if(vis[v]) continue;
            vis[v] = 1;
            for(auto child: g[v]){
               int child_v = child.first;
               double child_wt = child.second;
                if(dist[child_v] < child_wt*wt){
                    dist[child_v] = child_wt*wt;
                    q.push({dist[child_v], child_v});
                }
            }
        }
        
        return dist[end];
    }
};