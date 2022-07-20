class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> dsum(n);
        for(int i=0;i<n;i++){
            int digit = nums[i];
            int sum = 0;
            while(digit){
                sum += digit%10;
                digit/=10;
            }
            
            dsum[i] = sum;
        }
        
        vector<pair<int,int>> v;
       int ans = -1;
        for(int i=0;i<n;i++){
            v.push_back({dsum[i], nums[i]});
        }
        sort(v.begin(), v.end());
        for(int i=1;i<n;i++){
            if(v[i].first==v[i-1].first){
                ans = max(ans, v[i].second + v[i-1].second);
            }
        }
        return ans;
    }
};