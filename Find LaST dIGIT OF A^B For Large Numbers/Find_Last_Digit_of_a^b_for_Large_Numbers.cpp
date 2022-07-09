   class solution{
    public:
   
    int getLastDigit(string a, string b) {
        // code here
        if(b.size()==1 && b[0]=='0') return 1;
        if(a.size()==1 && a[0]=='1') return 1;
        
        
        int exponent = (modulo(4,b)==0) ? 4 : modulo(4,b);
        
        int ans = pow(a[a.size()-1]-'0', exponent);
        
        return ans%10;
        
    }
    
   int modulo(int a,string b){
        int ans = 0;
        for(int i=0;i<b.size();i++){
            ans = (ans*10 + b[i]-'0')%a;
        }
        
        return ans;
    }
};
