class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        for(char c:s) m[c]++;
        bool is_odd = false;
        int ans = 0;
        for(auto it:m){
            if(it.second%2 != 0) is_odd = true;
            ans += it.second/2;
        }
        
        return is_odd ? (ans*2)+1 : ans*2;
    }
};