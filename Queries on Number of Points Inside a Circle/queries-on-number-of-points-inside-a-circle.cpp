class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto v:queries){
            int count = 0, x = v[0], y = v[1], r = v[2];
            for(auto vec:points){
                int xp = vec[0], yp = vec[1];
                if(pow((xp-x),2) + pow((yp-y),2) <= pow(r,2))
                    count++;
            }
            ans.push_back(count);
        }
        
        return ans;
    }
};