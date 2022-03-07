class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    
    bool isPal(string &s,int l,int r){
        while(l<=r){
            if(s[l++]!=s[r--]) return false;
        }
        
        return true;
    }
    
    void dfs(int index, string &s){
        if(index==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isPal(s,index,i)){
                path.push_back(s.substr(index, i-index+1));
                dfs(i+1,s);
                path.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
       dfs(0,s); 
        
        return ans;
    }
};