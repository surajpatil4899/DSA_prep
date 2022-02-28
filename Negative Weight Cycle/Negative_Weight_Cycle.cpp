class Solution {
public:
    const int inf = 1e9+10;
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> dist(n, inf);
	    dist[0] = 0;
	    for(int i=0;i<n-1;i++){
	        for(auto &v: edges){
	            dist[v[1]] = min((long long)dist[v[0]]+v[2], (long long)dist[v[1]]);
	        }
	    }
	    for(auto &v: edges){
	        if(dist[v[1]] > dist[v[0]] + v[2]) return true;
	    }
	    
	    return false;
	}
};