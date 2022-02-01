class Solution {
public:
    
    double calc(double x,int n){
      if(n==0) return 1;
        double res = calc(x,n/2);
        if(n%2 != 0){
            return x * res * res;
        }
        else{
            return res * res;
        }
    }
    double myPow(double x, int n) {
        if (n < 0) n = abs(n),x = 1/x;
        return calc(x,n);
    }
};