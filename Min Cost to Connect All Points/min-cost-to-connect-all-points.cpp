class Solution {
public:

int parent[1001];
int size[1001];

void make(int v){
   parent[v] = v;
   size[v] = 1;
}

int find(int v){
   if(v == parent[v]) return v;

   return parent[v] = find(parent[v]);
}



void Union(int a,int b){
   a = find(a);
   b = find(b);
   if(a != b){
      if(size[a] < size[b])
         swap(a,b);
      parent[b] = a;
      size[a] += size[b];
   }

}

    int minCostConnectPoints(vector<vector<int>>& ps) {
       int n = ps.size();
       vector<pair<int,pair<int,int>>> g;
       for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
               g.push_back({abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1]),{i,j}}); 
          }
       } 
        
    for(int i=1;i<=n;i++) make(i);
        
        sort(g.begin(), g.end());
        int cost = 0;
        
        for(auto &edge: g){
            int wt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            if(find(u) == find(v)) continue;
            Union(u,v);
            cost += wt;
        }
        
        return cost;
    }
};