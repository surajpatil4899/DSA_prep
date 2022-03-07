class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        int cus = 1;
        int maxs = 1;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i] == nums[i-1]+1){
                    cus+=1;
            }
            else{
                maxs = max(maxs,cus);
                cus = 1;
            }
        }
       }
        return max(maxs,cus);
    }
};