class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_map<string,int> m;
        int unpaired = 0, samec = 0;

        for(auto it:words){
                        
            if(it[0]==it[1]){
               if(m[it] > 0){
                   unpaired--;
                   m[it]--;
                   ans += 4;
               }else{
                   unpaired++;
                   m[it]++;
               }
            }  else{
                string temp = it;
                reverse(temp.begin(), temp.end());
                if(m[temp] > 0){
                    m[temp]--;
                    ans += 4;
                }else m[it]++;
            }     
  
        }
    
        if(unpaired > 0) ans += 2;
        
        
        return  ans;
    }
};