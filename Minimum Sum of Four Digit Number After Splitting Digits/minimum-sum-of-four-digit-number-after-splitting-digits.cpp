class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
         
        vector<int> nums;
        for(char i:s)nums.push_back(i-'0');
        
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        
        int num1 = (nums[0]*10) + nums[3];
        int num2 = (nums[1]*10) + nums[2];
        ans = num1 + num2;
        
        return ans;
    }
};