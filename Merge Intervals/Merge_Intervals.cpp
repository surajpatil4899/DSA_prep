class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> p = intervals[0];
       for(auto it: intervals){
           if(it[0]<=p[1]) p[1] = max(it[1],p[1]);
           else{
               ans.push_back(p);
               p = it;
           }
       }
        ans.push_back(p);
        return ans;
    }
};