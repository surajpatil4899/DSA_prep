class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l,r,t,d,p;
        l = 0;
        r = matrix[0].size()-1;
        t = 0;
        d = matrix.size()-1;
        p = 0;
        int i;
        vector<int> ans;
        while(t<=d && l<=r){
            if(p==0){
                for(i=l;i<=r;i++)
                    ans.push_back(matrix[t][i]);
                    t++;
            }else if(p==1){
                for(i=t;i<=d;i++)
                    ans.push_back(matrix[i][r]);
                    r--;                
            }else if(p==2){
                for(i=r;i>=l;i--)
                   ans.push_back(matrix[d][i]); 
                  d--;
            }else if(p==3){
                for(i=d;i>=t;i--)
                    ans.push_back(matrix[i][l]);
                l++;
            }
            p = (p+1)%4;
        }
        
        return ans;
    }
};