class Solution {
public:
    string smallestNumber(string s) {
        string ans, stack;
        int n = s.size();
        for(int i=0;i<=n;i++){
             stack.push_back('1'+i);
            if(i == s.size() || s[i] == 'I'){
                while(!stack.empty()){
                    ans.push_back(stack.back());
                    stack.pop_back();
                }
            }
        }
        
            
        return ans;
    }
};