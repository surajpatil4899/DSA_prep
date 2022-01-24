// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
       long int ans;
       long int hi = n;
        long int lo = 0;
        while(hi - lo > 1){
           long int mid = (hi+lo)/2;
            if(isBadVersion(mid)){
                hi = mid;
            }
            else{
               lo = mid + 1;
            }
        }
        
        if(isBadVersion(lo))
            ans = lo;
        else if(isBadVersion(hi))
            ans = hi;
        
        return ans;
    }
};