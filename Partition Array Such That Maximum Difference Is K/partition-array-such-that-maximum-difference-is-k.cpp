class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1;
        int curr = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]-nums[curr] > k){
                ans++;
                curr = i;
            }
        }
        
        return ans;
    }
};