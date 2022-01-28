class Solution {
public:
    set<vector<int>> ans;
    
    void generate(vector<int>& nums,int index){
        if(index==nums.size()){
            ans.insert(nums);
      
        }
        
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            generate(nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        generate(nums,0);
        
        vector<vector<int>> result(ans.begin(), ans.end());
        
        return result;
    }
};