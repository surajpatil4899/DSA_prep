class Solution {
public:
    vector<vector<int>> ans;
    void generate(int n, int k, int i, vector<int> &elements){
        if(elements.size()==k){
            ans.push_back(elements);
            return;
        }
        
        //not taking i
        if(i<=n)
        generate(n,k,i+1,elements);
        
        //taking i
        if(i<=n){
           elements.push_back(i);
            generate(n,k,i+1,elements);
            elements.pop_back(); //backtracking
        }
        
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> elements;
        generate(n,k,1,elements);
        
        return ans;
    }
};