class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
         int res = INT_MIN;
         int cMax = 1;
        int cMin = 1;
        
        for(int n:nums){
            if(n<0){
              swap(cMax,cMin); //if n is -ve the swap it will give max
            }
                cMax = max(n*cMax,n);
                cMin = min(n*cMin,n);
                res = max(res,cMax);

        }
        
        return res;
    }
};