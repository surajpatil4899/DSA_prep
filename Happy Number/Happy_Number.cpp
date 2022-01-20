class Solution {
public:
    bool isHappy(int n) {
        // bool flag = false;
        set<int> s;
        int curr, index;
        
        while(1){
            curr = 0;
            while(n){
                index = n%10;
                curr += index*index;
                n /= 10;
            }
            if(curr==1) return true;
            else if(s.find(curr) != s.end()){
               return false;
            }
            
            s.insert(curr);
            n = curr;
        }
        
        // return false;
    }
};