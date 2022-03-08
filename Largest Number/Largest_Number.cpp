class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> number;
        
        for(auto n:nums){
            number.push_back(to_string(n));
        }
        
       sort(number.begin(), number.end(), [](string a,string b){
          return a+b > b+a; 
       });
        
        string ans="";
        for(auto s:number){
            ans += s;
        }
        
        return ans[0] == '0' ? "0" : ans;
    }
};