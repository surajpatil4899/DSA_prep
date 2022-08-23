class Solution {
public:
    string largestPalindromic(string num) {
      vector<int>v(10,0);
    //create a vector to store count of occurances of each digit
    for(auto s:num){
        int val=s-'0';
        v[val]++;
    }
    //case where we return 0
    int flag=0;
    for(int i=1;i<=9;i++){
        if(v[i]>=1)
            flag=1;
    }
    if(!flag && v[0]>0){
        return "0";
    }
    //find the largest value which is single 
    string res;
    string singleval;
    for(int i=0;i<=9;i++){
        if(v[i]%2==1)
            singleval=to_string(i);
    }
    
    //make the largest possible string
    for(int i=9;i>=0;i--){
        if(i==0 && res.empty())
            break;
        int times=v[i]/2;
        while(times){
            string curr=to_string(i);
            res+=curr;
            times--;
        }
    }
    string revres=res;
    reverse(res.begin(),res.end());
    return revres+singleval+res;
        
    }
};