class Solution {
public:
    string minWindow(string s, string t) {
     unordered_map<char,int> m;
        for(char c:t) m[c]++;
        int lo = 0, minl = INT_MAX, mins = 0, count = 0;
       for(int high=0;high<s.size();high++){
           if(m[s[high]]>0) count++;
           m[s[high]]--;
           if(count==t.size()){
               while(lo<high && m[s[lo]] < 0) m[s[lo]]++, lo++;
               if(minl > high-lo) minl = high - (mins = lo) + 1;
               m[s[lo++]]++;
               count--;
           }
       }
      
     return (minl==INT_MAX) ? "" : s.substr(mins,minl);
    }
};