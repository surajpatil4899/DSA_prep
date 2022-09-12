class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> mp;
        for(int i:nums){
          if(i%2==0) mp[i]++;
        }
        
        int ans = -1;
        int maxi = -1;
        for(auto p:mp){
            if(p.second>maxi){
                maxi = p.second;
                ans = p.first;
            }
        }
    
        
        return ans;
    }
};