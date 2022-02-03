class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int N = nums.size() , sum = 0 , ans = INT_MAX  ;
        int left = 0 , right = N-1 ;
        sort(nums.begin(),nums.end());
        int currentsum = nums[0]+nums[1]+nums[2] ;
        
        for(int i=0;i<N-2;i++)
        {
            left = i+1 ;
            right = N-1 ;
            
            while(left<right)
            {
                sum = nums[i]+nums[left]+nums[right] ;
                
                if(sum==target)
                    return target ;
                
                if(abs(target-sum)<abs(target-currentsum))
                {
                    currentsum = sum ;
                }
                if(sum>target)
                    right-- ;
                
                if(sum<target)
                    left++ ;
            }
            
        } 
        return currentsum ;
    }
};