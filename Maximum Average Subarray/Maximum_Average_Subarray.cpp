class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        double maxi = INT_MIN;
        
        
       for(int i=0;i<k;i++){
           sum += nums[i];
       }
        maxi = max(maxi, sum);
      for(int i=k;i<nums.size();i++){
        sum += nums[i] - nums[i-k];
         maxi = max(maxi, sum);
      }
    
         maxi /= k;
        return maxi;
    
    }
};