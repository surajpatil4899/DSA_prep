class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        
        int l = 0,h = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot)l++;
            if(nums[i]==pivot)h++;
        }
        
        int st = 0, end = l+h;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > pivot){
                ans[end] = nums[i];
                end++;
            }else if(nums[i] < pivot){
                ans[st]  = nums[i];
                st++;
            }else if(nums[i]==pivot){
                ans[l] = nums[i];
                l++;
            }
        }
        
        return ans;
    }
};