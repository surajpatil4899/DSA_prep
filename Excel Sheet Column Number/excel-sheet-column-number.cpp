class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for(int i=0;i<s.size();i++){
            ans = s[i] - 64 + (ans*26);
        }
        
        return ans;
    }
};