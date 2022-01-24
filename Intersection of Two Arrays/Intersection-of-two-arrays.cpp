class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
         unordered_set<int> s;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        for(int i=0;i<nums2.size();i++){
           auto it = lower_bound(nums1.begin(), nums1.end(),nums2[i]);
            if(it != nums1.end()){
                if(*it == nums2[i]){
                    s.insert(*it);
                }
            }
        }
        
        vector<int> v(s.begin(), s.end());
        
        return v;
    }
};