class Solution {
public:
     vector<vector<int>> ans;
    
    void generate(vector<int>& nums,int index,vector<int>& elements){
     
            ans.push_back(elements);
           
        
     
      for(int i=index;i<nums.size();i++){  
          if(i>index && nums[i-1] == nums[i]) continue;
        elements.push_back(nums[i]);
        generate(nums,i+1,elements);
        elements.pop_back();
      }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<int> elements;
        
        generate(nums,0,elements);
      
       
        
        return ans;
    }
};