class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int p = 1;
        int zc = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0) p *= nums[i];
             else if(nums[i]==0) zc++;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0 && zc==0)  ans.push_back(p/nums[i]); 
            else if(nums[i] != 0 && zc>=1) ans.push_back(0);
            else if(nums[i]==0 && zc==1) ans.push_back(p);
            else if(zc>=2) ans.push_back(0);
        }
        
        return ans;
    }
};