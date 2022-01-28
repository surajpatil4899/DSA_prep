class Solution {
public:
    vector<vector<int>> ans;
    
    
    void generate(vector<int>& nums,int index){
        if(index==nums.size()){
            ans.push_back(nums);
       
        }
            
       for(int i=index;i<nums.size();i++){ 
           
       swap(nums[i],nums[index]);
        generate(nums,index+1);
      swap(nums[i],nums[index]);     
          
     }  
        
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
          
        generate(nums,0);
        
        return ans;
    }
};