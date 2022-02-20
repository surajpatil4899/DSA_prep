class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> indegree(n, 0); //initialized witn 0 of size n
         for(auto e: edges){    //e consists oof vector of edge
             indegree[e[1]]++;
         }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};