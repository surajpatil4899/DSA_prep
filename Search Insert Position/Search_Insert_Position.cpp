class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = nums.size();
        
       for(int i=0;i<nums.size();i++){
           if(nums[i]==target){
               index = i;
               break;
           }
       }
        
       if(index==nums.size()){
           for(int i=0;i<nums.size();i++){
               if(nums[i]>target){
                   index = i;
                   break;
               }
           }
       }
        
        return index;
    }
};