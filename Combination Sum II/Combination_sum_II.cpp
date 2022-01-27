class Solution {
public:
    vector<vector<int>> ans;
    
    void generate(vector<int> &candidates, vector<int> &elements,int start,int target){
         if(target<0) return;
        if(target==0){
            ans.push_back(elements);
            return;
        }
        
       for(int i=start;i<candidates.size();i++){
           elements.push_back(candidates[i]);
        generate(candidates, elements, i+1,  target-candidates[i]);
        elements.pop_back();
           
           //for checking duplicates
           while(i+1<candidates.size() && candidates[i+1]==candidates[i]){
                i++;
            } 
       }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> elements;
        // if(candidates.size()==0)
        //     return {};
        sort(candidates.begin(), candidates.end());
        
          generate(candidates, elements, 0, target);
            
     
        
        return ans;
    }
};