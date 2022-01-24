class Solution {
public:
    bool isPerfectSquare(int num) {
       int s=1;
        int e=num;
        int long mid = s+(e-s)/2;
        while(s<=e){
            if(mid*mid==num)
                return true;
           if(num>mid*mid)
               s = mid+1;
            if(num<mid*mid)
                e = mid-1;
           mid = s+(e-s)/2; 
        }
       
        return false;
    }
};