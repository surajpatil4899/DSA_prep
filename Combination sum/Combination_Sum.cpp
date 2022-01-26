class Solution {
public:
    vector<vector<int>> ans;
    
    void search(vector<int>& candidates, int i, vector<int>& elements, int currSum, int target){
        currSum += candidates[i];
        elements.push_back(candidates[i]);

        if (currSum == target){
            ans.push_back(elements);
            elements.pop_back(); // for getting out element pushed before call
            return;
        }

        for (int j = i; j < candidates.size() && currSum + candidates[j] <= target; j++){
            search(candidates, j, elements, currSum, target);
        }
        elements.pop_back(); //backtrack step
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> elements;
        for (int i = 0; i < candidates.size() && candidates[i] <= target; i++){
            search(candidates, i, elements, 0, target);
        }	
        return ans;
    }
};