class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans = {0,1};
        
        for(int i=1;i<n;i++){
            vector<int> rev = ans;
            reverse(rev.begin(), rev.end());
            
            for(int j=0;j<rev.size();j++){
                rev[j] |= 1 << i;
            }
            
            ans.insert(ans.end(), rev.begin(), rev.end());
        }
        
        return ans;
    }
};