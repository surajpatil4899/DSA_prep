class Solution {
public:
    
    int find(int n,vector<int> &p){
        if(n==p[n]) return n;
        
        return find(p[n], p);
    }
  
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
     vector<int> parent(1001, 0);
        for(int i=0;i<parent.size();i++)
            parent[i] = i;
        
        vector<int> ans;
        for(auto v: edges){
            int n1 = v[0], n2 = v[1];
            int p1 = find(n1, parent);
            int p2 = find(n2, parent);
            if(p1==p2) ans = v;
            parent[p1] = p2;
        }
        
        return ans;
    }
};