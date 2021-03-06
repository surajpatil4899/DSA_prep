class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        int mid;
        while(lo<hi){
             mid = lo + (hi-lo)/2;
            if(nums[mid]<nums[mid+1]) lo = mid + 1;
            else hi = mid;
        }
        
        return hi;
    }
};