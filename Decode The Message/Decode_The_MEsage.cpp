class Solution {
public:
    string decodeMessage(string key, string message) {
        map<int,char> mp;
        
        int i = 0;
        for(char c:key){
            if(i<26 && c != ' ' && mp[c-'a']==0){
                mp[c-'a'] = i+'a';
             i++;
           }
        }
        
        string ans = "";
        
        for(auto c:message){
            ans += (c==' ') ? ' ' : mp[c-'a'];
        }
        
        return ans;
    }
};