class Solution {
public:
 
    int jump(vector<int>& nums) {
      int curr = 0;
        int farthest = 0;
        int jumps = 0;
        for(int i=0;i<nums.size()-1;i++){
            farthest = max(farthest, nums[i]+i);
            if(curr==i){
                curr = farthest;
                jumps++;
            }
        }
        
        return jumps;
    }
};