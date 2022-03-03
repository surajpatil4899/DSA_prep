class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>> q;
        for(auto p: m){
            q.push({p.second, p.first});
        }
        vector<int> ans;
        while(k--){
            auto p = q.top();
            q.pop();
            ans.push_back(p.second);
        }
        
        return ans;
    }
};