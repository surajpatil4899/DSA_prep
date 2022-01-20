class Solution {
public:
    int lengthOfLastWord(string s) {
//         int len=0;
//         int n = s.size()-1;
//         while(n>=0){
//             if(s[n] != ' '){
//                 len++;
//                 n--;
//             }
//             else if(len>0) return len;
//         }
        
//         return len;
         int count=0;

    for(int i=s.size()-1; i>=0; i--){
        
        if(s[i]==' ')
            count=0;
        else{
            count++;
            if(i>0 && s[i]!=' ' && s[i-1]==' ')
                return count;
            else if(i==0)
                return count;
        }
        
    }
    
    
    return 1;
    }
};