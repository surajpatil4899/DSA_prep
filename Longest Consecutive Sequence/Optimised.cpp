class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> s;
        for(int num:nums){
             s.insert(num);
        }
        
        int ls = 0;
        for(int num:nums){
            if(!s.count(num-1)){
                int cn = num;
                int cs = 1;
                while(s.count(cn+1)){
                    cs++;
                    cn++;
                }
                
                ls = max(ls,cs);
            }
        }
        
        return ls;
    }
};