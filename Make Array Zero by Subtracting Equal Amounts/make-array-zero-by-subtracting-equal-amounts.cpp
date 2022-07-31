class Solution {
public:
    int minimumOperations(vector<int>& nums) {
      vector<int> hsh(101, 0);
        
        for(int i=0;i<nums.size();i++){
           hsh[nums[i]]++;
        }
        
        int ans = 0;
        for(int i=1;i<101;i++){
            if(hsh[i]>0) ans++;
        }
        
        return ans;
    }
};