class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char,int> m;
        unordered_map<char,int> c;
        int p = 0;
        for(int i=0;i<t.size();i++){
                if(t[i]==s[p]){
                    m[s[p]]++;
                    p++;
                }
            
        }
        for(int i=0;i<s.size();i++){
           c[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(m[s[i]]!=c[s[i]]) return false;
        }
        
        return true;
    }
};