class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        unordered_map<char,int> m;
        
        for(char c:p) m[c]++;
        
        int count = m.size();
        int i=0;
        int j=0;
        
        while(j<s.size()){
            
          if(m.find(s[j]) != m.end()){
              m[s[j]]--;
              if(m[s[j]]==0) count--;
          }
            
            if(j-i+1<p.size()) j++;
            
            else if(j-i+1==p.size()){
                if(count == 0) ans.push_back(i);
                if(m.find(s[i]) != m.end()){
                    m[s[i]]++;
                    if(m[s[i]]==1) count++;
                }
                i++;
                j++;
            }
        }
        
        return ans;
    }
};