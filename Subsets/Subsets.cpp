class Solution {
public:
    vector<vector<int>> all_subsets;
    
    void generate(vector<int> &subset, int i, vector<int> &nums){
        //base condition
        if(i==nums.size()){
            all_subsets.push_back(subset);
            return;
        }
        
        
        //not consider ith element
        generate(subset, i+1, nums);
        
        //consider ith element
        subset.push_back(nums[i]);
        generate(subset, i+1, nums);
        subset.pop_back();   //backtracking step
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> empty;
        generate(empty, 0, nums);
        return all_subsets;
    }
};