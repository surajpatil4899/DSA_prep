class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        int dp[201]{};
        
        for(int i:nums){
            dp[i] = i>=diff ? dp[i-diff] + 1 : 1;
            if(dp[i]>=3) ans++;
        }
        
        return ans;
    }
};