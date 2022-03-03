class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& a) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<a.size();i++){
            m[a[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto it: m){
            int val = it.first;
            vector<int> res;
            for(auto x: it.second){
                res.push_back(x);
                if(val==res.size()){
                    ans.push_back(res);
                    res.clear();
                }
            }
        }
        
        return ans;
    }
};