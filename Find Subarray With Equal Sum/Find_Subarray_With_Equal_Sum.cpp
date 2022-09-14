class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
            unordered_map<int,int> mp;
        
          for(int i=1;i<nums.size();i++){
              int sum = nums[i-1]+nums[i];
              mp[sum]++;
              if(mp[sum] > 1) return true;
          }
        
    
        return false;
    }
};