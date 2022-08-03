class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size()-1;){
            if(nums[i] == nums[i+1]){
                ans++;
                i++;
            }else i+=2;
        }
      
        
        return ans + ((nums.size()-ans)%2!=0);
    }
};