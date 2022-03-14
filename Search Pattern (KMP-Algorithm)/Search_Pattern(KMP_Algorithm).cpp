class Solution
{
    public:
        vector <int> search(string P, string T)
        {
            int m = P.size();
            vector<int> ans;
            vector<int> lps(P.size(), 0);
         int j = 0, i = 1;
	    while(i<P.size()){
	        if(P[i]==P[j]){
	            lps[i] = j+1;
	            i++;
	            j++;
	        }else{
	            if(j==0)i++;
	            else j = lps[j-1];
	        }
	    }
	    
    
    int n = T.size();
     i = 0; j = 0;
    while(i < n){
        if(P[j] == T[i]){
            i++;
            j++;
        }
        if( j == m){
            ans.push_back(i-(m-1));
            j = lps[j-1];
        }
        else if(i < n && P[j] != T[i]){
            if(j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
            
            return ans;
        }
     
};