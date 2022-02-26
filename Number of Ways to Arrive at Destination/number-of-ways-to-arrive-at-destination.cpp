class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1000000007;
        vector<vector<pair<int, int>>> g(n);
        for(auto &road: roads) {
            g[road[0]].push_back({road[1], road[2]});
            g[road[1]].push_back({road[0], road[2]});
        }
        
        int source = 0;
        
        vector<long long> dist(n, LONG_MAX);
        vector<int> ways(n, 0);
        
          set<pair<long,long>> st;
         ways[0] = 1;
        dist[source] = 0;
        
        st.insert({0, source});
        while(st.size()>0){
            auto node = *st.begin();
            long v = node.second;  
           long v_dist = node.first;
            
            st.erase(st.begin());
            
            if(dist[v]<v_dist) continue;

            for(auto child: g[v]){
                int child_v = child.first;
                int wt = child.second;
                if(dist[v] + wt < dist[child_v]){
                    dist[child_v] = dist[v] + wt;
                    ways[child_v] = ways[v];
                 st.insert({dist[child_v], child_v}); 
                }
                else if(dist[v] + wt == dist[child_v]){
                    ways[child_v] = (ways[child_v] + ways[v])%MOD;
                }
            }
        }
        
        return ways[n-1];
    }
};