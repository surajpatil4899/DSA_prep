class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> l(n);
        vector<int> r(n);
        
        int maxl = INT_MIN;
        int maxr = INT_MIN;
        
        for(int i=0;i<n;i++){
            l[i] = max(maxl,height[i]);
            maxl = max(maxl,height[i]);
        }
        for(int i=n-1;i>=0;i--){
            r[i] = max(maxr,height[i]);
            maxr = max(maxr,height[i]);
        }
        
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(height[i]<l[i] && height[i]<r[i])
                ans += min(l[i],r[i]) - height[i];
        }
        
        return ans;
    }
};