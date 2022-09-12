class Solution {
public:
    
    
    void set(int &flag,int n){
        flag = flag | (1<<n);
    }
    
    
    bool check(int &flag,int n){
       return flag & (1<<n);
    }
    
    
    int partitionString(string s) {
        int ans = 1;
        int flag=0;
        
        for(char c:s){
            int n = c-'a';
            if(check(flag,n)){
                ans++;
                flag = 0;
            }
            
            set(flag,n);
        }
        
        
        return ans;
    }
};