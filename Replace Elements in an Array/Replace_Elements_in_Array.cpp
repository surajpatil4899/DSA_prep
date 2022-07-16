class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        for(auto op:operations){
            nums[mp[op[0]]] = op[1];
            int ind = mp[op[0]];
            mp.erase(op[0]);
            mp[op[1]] = ind;
        }
        
        return nums;
    }
};