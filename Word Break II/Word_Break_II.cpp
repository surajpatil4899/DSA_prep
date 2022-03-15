class Solution {
public:
    vector<string> ans;
 
    void solve(vector<string>& word,string &s,string st,int pos){
        if(pos==s.size()){
            ans.push_back(st);
            return;
        }
        
        
        st += " ";
        for(int i=pos;i<s.size();i++){
            string tmp = s.substr(pos,i+1-pos);
            if(find(word.begin(),word.end(),tmp) != word.end()){
               solve(word,s,st+tmp,i+1);
        }
      } 
    }
    vector<string> wordBreak(string s, vector<string>& word) {
        for(int i=0;i<s.size();i++){
            string tmp = s.substr(0,i+1);
            if(find(word.begin(),word.end(),tmp) != word.end()){
                solve(word,s,tmp,i+1);
            }
        }
        
        return ans;
    }
};