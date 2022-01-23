class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
      vector<string> v;
        int c=1;
        int i=0;
        while(i<target.size()){
            if(target[i]==c){
                v.push_back("Push");
                i++;
            }
            else{
                v.push_back("Push");
                v.push_back("Pop");
            }
            c++;
        }
        
        return v;
    }
};