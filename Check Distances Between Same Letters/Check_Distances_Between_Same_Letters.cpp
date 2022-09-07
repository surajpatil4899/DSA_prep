class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> mp(26, 0);
        vector<int> ans(26, 0);
        int n = s.size();
        for(int i=0;i<n;i++) mp[s[i]-'a']++;
        for(int  i=0;i<n-1;i++){
            int count = 0;
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    ans[s[i]-'a'] = count;
                    break;
                }
                count++;
            }
        }
        
        for(int i=0;i<26;i++){
            if(mp[i] != 0 && distance[i] != ans[i]) return false;
        }
     
        
        return true;
    }
};