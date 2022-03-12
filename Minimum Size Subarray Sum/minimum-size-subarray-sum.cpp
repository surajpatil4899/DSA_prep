class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      
        int j = 0;
        int sum = 0;
        int maxl = INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            while(sum>=target){
                maxl = min(maxl,(i-j)+1);
                sum -= nums[j++];
            }
        }
        
        return maxl==INT_MAX ? 0 : maxl;
    }
};