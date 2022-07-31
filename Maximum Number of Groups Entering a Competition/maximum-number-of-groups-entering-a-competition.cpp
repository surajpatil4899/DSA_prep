class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int ans = 0;
        for(int i=1;i<=grades.size();i++){
            if(n>=i){
                n -= i;
                ans++;
            }else break;
        }
        
        return ans;
    }
};