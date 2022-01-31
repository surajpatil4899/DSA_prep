class Solution {
public:
    long int convertToLong(int &num){
        return ((long int)(num) );
    }
    int reverse(int x) {
        bool flag = (x<0);
        x = abs(x);
        if(x>INT_MAX) return 0;
        int rev = 0;
        while(x>0){
            int rem = x%10;
            if( ((convertToLong(rev) *10) + rem) > INT_MAX )
                return 0;
            rev = (rev*10)+rem;
            x /= 10;
        }
        
        if(flag) return -rev;
        return rev;
    }
};