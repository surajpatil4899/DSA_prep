class Solution {
public:
    int solve(vector<int> &s){
        int max_so_far = INT_MIN, max_end = 0;
        for(int i=0;i<s.size();i++){
            max_end += s[i];
            if(max_so_far < max_end) max_so_far = max_end;
            
            if(max_end < 0) max_end = 0;
        }
        
        return max_so_far;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n =  nums1.size();
        vector<int> s1(n);
        vector<int> s2(n);
        
        int sum1 = 0, sum2 = 0;
        for(int i=0;i<n;i++){
            sum1 += nums1[i];
            sum2 += nums2[i];
            s1[i] = nums1[i] - nums2[i];
            s2[i] = nums2[i] - nums1[i];
        }
        
        int res1 = solve(s1) + sum2;
        int res2 = solve(s2) + sum1;
        
        return max(res1, res2);
        
    }
};