class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto c:nums)mp[c]++;
        int pair = 0, left = 0;
        for(auto p:mp){
            pair += p.second/2;
            left += p.second%2;
        }
        vector<int> ans;
        ans.push_back(pair);
        ans.push_back(left);
        
        return ans;
    }
};