class Solution {
public:
    string intToRoman(int num) {
         unordered_map<int,string>m;
        m[1]="I",m[5]="V",m[10]="X",m[50]="L",m[100]="C",m[500]="D",m[1000]="M";
        int x=1;
        string s="";
        while(num>0)
        {
            int a=num%10; // Last digit of a number
            a*=x; // Multiply by its place value
            while(a>0)
            {
                if(m.find(a)!=m.end()) // find the digit in the map
                    s=m[a]+s,a=0;
                else if(m.find(a+x)!=m.end()) // or find the approx nearest in the map.
                    s=m[x]+m[a+x]+s,a=0;
                else 
                    s=m[x]+s,a-=x; // iterate the place value mapped value until it matches the map value
            }
            num/=10; // remove the last digit from the number
            x*=10; // increment the place value.
        }
        return s;
    }
};