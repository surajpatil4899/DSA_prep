class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> hsh(n, 0);
        
        for(int i=0;i<n;i++){
            hsh[edges[i]] += i;
        }
        
        int ans = -1;
        long long maxi = -1;
        for(int i=0;i<n;i++){
            if(hsh[i]>maxi){
                maxi = hsh[i];
                ans = i;
            }
        }
        
        return ans;
    }
};