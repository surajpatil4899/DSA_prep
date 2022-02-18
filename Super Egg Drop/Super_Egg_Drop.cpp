class Solution {
public:
     int dp[10001][101];
    int solve(int f,int e){
        if(e==1) return f;
        if(f==1 || f==0) return f;
        
        if(dp[f][e] != -1) return dp[f][e];
        
        int mn = INT_MAX;
        int l=1,h=f,temp=0;
        while(l<=h){
            int mid = (l+h)/2;
            int left = solve(mid-1,e-1);
            int right = solve(f-mid,e);
            temp = 1 + max(left,right);
            if(left<right){
                l = mid+1;
            }else h = mid-1;
            
            mn = min(mn, temp);
        }
        
        return dp[f][e] = mn;
    }
    int superEggDrop(int k, int n) {
          memset(dp, -1, sizeof(dp));
        return solve(n,k);
    }
};