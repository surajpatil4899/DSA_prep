class Solution {
public:
    char repeatedCharacter(string s) {
       vector<int> hsh(26, 0);
        char ans;
        for(char c:s){
            hsh[c-'a']++;
            if(hsh[c-'a']==2){
                ans = c;
                break;
            }
        }
        
        return ans;
    }
};