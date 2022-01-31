class Solution {
public:
//     vector<vector<int>> all_subsets;
    
//     void generate(vector<int> &subset, int i, vector<int> &nums){
//         //base condition
//         if(i==nums.size()){
//             all_subsets.push_back(subset);
//             return;
//         }
        
        
//         //not consider ith element
//         generate(subset, i+1, nums);
        
//         //consider ith element
//         subset.push_back(nums[i]);
//         generate(subset, i+1, nums);
//         subset.pop_back();   //backtracking step
    // }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> all_subsets;
        
        int n= nums.size();
       int count = (1<<n);
        for(int mask=0;mask<count;mask++){
            vector<int> subset;
            for(int j=0;j<n;j++){
                if((mask&(1<<j)) != 0) subset.push_back(nums[j]); 
            }
            
            all_subsets.push_back(subset);
        }
        
        return all_subsets;
    }
};