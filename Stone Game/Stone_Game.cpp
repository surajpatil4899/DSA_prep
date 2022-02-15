class Solution {
public:
    int dp[505][505];
    int alice(vector<int> &piles,int l,int r){
        if(l==r-1) return max(piles[l], piles[r]);
        
        if(dp[l][r] != -1) return dp[l][r];
        
        int left = piles[l] + max(alice(piles,l+2,r), alice(piles,l+1,r-1));
        int right = piles[r] + max(alice(piles,l+1,r-1), alice(piles,l,r-2));
        
        return dp[l][r] = max(left,right);
        
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        
        int l = 0 , r = piles.size()-1;
        int aliceScore = alice(piles,l,r);
        int totalScore = 0;
        for(int i=0;i<r;i++) totalScore += piles[i];
        
        return aliceScore > (totalScore - aliceScore);
        
    }
};