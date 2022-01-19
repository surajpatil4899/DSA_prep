class Solution {
public:
    bool isValid(string s) {
        bool flag = false;
        unordered_map<char,int> symbol = {{'[',-1},{'{',-2},{'(',-3},{']',1},{'}',2},{')',3}};
        stack<char> st;
        for(char bracket:s){
            if(symbol[bracket] < 0){
                st.push(bracket);
            }
            else{
                if(st.empty()) return flag = false;
                char top = st.top();
                st.pop();
                if(symbol[top]+symbol[bracket] != 0){
                 return flag = false;  
                }
            }
        }
        
        if(st.empty()) return flag = true;
       return flag = false;
        
        
    }
};