class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        int tmp;
        string base;
        for(int i=2;i<=n-2;i++){
            tmp = n;
            while(tmp){
                base.push_back(tmp%i);
                tmp /= i;
            }
            
            int st = 0, end = base.size()-1;
            while(st<end){
                if(base[st++] != base[end--]) return false;
            }
            
            base.clear();
        }
        
        return true;
    }
};

