 if(numRows==1)
            return s;
        int cycle = numRows*2-2;
        string ans = "";
        int increment = cycle;
        for(int i  = 0;i<numRows;i++){
            if(increment==0)
                    increment = cycle;
            for(int j = i;j<s.length();j+=cycle){         
                ans+=s[j];
                int second = j+increment;
                if(j!=0&&j!=numRows-1&&second<s.length()&&second-j<cycle){
                    ans+=s[second];
                }
            }
            increment-=2;      

        }
        return ans;