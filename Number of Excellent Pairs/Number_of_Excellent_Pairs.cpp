class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        long long ans = 0;
        vector<int> bit_n;
        for(int i:s){
            int count = __builtin_popcount(i);
            if(count*2 >= k) ans++;
            bit_n.push_back(count);
        }
        
        
        
        sort(bit_n.begin(), bit_n.end());
        
        int i = 0, j = bit_n.size() - 1;
        
        while(i<j){
            if(bit_n[i] + bit_n[j] >= k){
                ans += (j-i)*2;
                j--;
            }
            else{
                i++;
            }
        }
        
        return ans;
    }
};