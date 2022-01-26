class Solution {
public:
    vector<string> ans;
unordered_map<int,string> umap = {{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
   
    void generate(int index, string digits,string &s){
        if(index==digits.size()){
            ans.push_back(s);
            return;
        }
        
        int n = digits[index] - '0';
        int len = umap[n].size();
        
        for(int i=0;i<len;i++){
            s.push_back(umap[n][i]);
            generate(index+1, digits, s);
            s.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
       
       string s = "";
        
        if(digits.size()==0) return {};
        
        generate(0,digits,s);
        return ans;
    }
};