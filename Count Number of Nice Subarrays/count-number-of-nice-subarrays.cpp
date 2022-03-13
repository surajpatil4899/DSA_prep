class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }
        int sum = 0;
        int ans = 0; 
       for(int i=0;i<nums.size();i++){
             sum += nums[i];
            if(sum==k) ans++;
           if(m.find(sum-k) != m.end()) ans+=m[sum-k];
           m[sum]++;
       }
        
        return ans;
    }
};