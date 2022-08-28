class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
      
        int sum = 0;
        vector<int> pre_sum;
        
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            pre_sum.push_back(sum);         
        }
        
        vector<int> ans(queries.size(), 0);
        int count = 0;
        
        for(int i=0;i<queries.size();i++){
             for(int j=0;j<nums.size();j++){
                  if(pre_sum[j] <= queries[i]) ans[i] = j+1;
                  else break;
             }
        }
        
        return ans;
    }
};