class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        
        for(int i=0;i<nums.size();i++) nums[i] = pow(nums[i],2);
        
        int l = 0;
        int r = nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[l]>nums[r]) ans[i] = nums[l++];
            else ans[i] = nums[r--];
        }
        
        return ans;
    }
};