class Solution {
public:
     set<vector<int>> ans;
    
    void generate(vector<int>& nums,int index,vector<int>& elements){
        if(index==nums.size()){
            ans.insert(elements);
            return;
        }
        
        // if(nums[index]==nums[index+1]) return;
        
        generate(nums,index+1,elements);
        
        elements.push_back(nums[index]);
        generate(nums,index+1,elements);
        elements.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<int> elements;
        
        generate(nums,0,elements);
      
        vector<vector<int>> result(ans.begin(), ans.end());
        
        return result;
    }
};