class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = 0, min = 1000;
        string s;
        
        for(int i=0;i<strs.size();i++){
            int len = strs[i].length();
            if(len < min){
                min = len;
                s = strs[i];
            }
        }
        
     
        for(int i=0;i<min;i++){
            for(int j=0;j<strs.size();j++){
                if(strs[j][i] != s[i]){
                  return s.substr(0,count);
                }
            }
            count++;
        }
        return s.substr(0,count);
    }
};