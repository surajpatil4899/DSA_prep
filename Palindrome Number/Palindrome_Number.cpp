class Solution {
public:
    bool isPalindrome(int x) {
        bool flag= false;
        int temp = x;
      long long int rev=0;
        if(temp<0){
          flag= false;
        }
else{
      while(temp!=0){
          int rem = temp%10;
          rev = rev*10 + rem;
          temp = temp/10;
      }
    }
        
     if(rev==x){
       flag = true;
     }
        
        else flag=false;
        
        
      return flag;
    }
};