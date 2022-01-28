class Solution {
public:
    vector<vector<int>> ans;
    
    void generate(vector<int>& nums,vector<int> &elements, vector<bool> &visited){
        if(elements.size()==nums.size()){
            ans.push_back(elements);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(visited[i]) continue;
            visited[i] = true;
            elements.push_back(nums[i]);
            generate(nums,elements,visited);
            elements.pop_back();
            visited[i] = false;
            
            while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> elements;
        int n = nums.size();
        vector<bool> visited(n, false);
        generate(nums,elements,visited);
        
        
        
        return ans;
    }
};