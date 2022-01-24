class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        bool match1 = true, match2 = true, match3 = true;
        
        for(int i=0;i<n;i++){
          if(!isupper(word[i]))
          {
              match1 = false;
              break;
          }
        }
        if(match1) return true;
        
         for(int i=0;i<n;i++){
          if(!islower(word[i])){
          
              match2 = false;
              break;
          }
        }
        if(match2) return true;
        
        if(!isupper(word[0])) match3 = false;
        if(match3){
            for(int i=1;i<n;i++){
          if(!islower(word[i]))
          {
              match3 = false;
              break;
          }
        }
      }
        if(match3) return true;
        
        
        return false;
    }
};