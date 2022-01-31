class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        
        map<int,int> hash;
  
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
           if(hash[nums[i]]==1)
              ans.push_back(nums[i]); 
        }
        
        return ans;
    }
};