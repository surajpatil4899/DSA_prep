class Solution{
  public:		
	int lps(string s) {
	    vector<int> a(s.size(), 0);
	    int j = 0, i = 1;
	    while(i<s.size()){
	        if(s[i]==s[j]){
	            a[i] = j+1;
	            i++;
	            j++;
	        }else{
	            if(j==0)i++;
	            else j = a[j-1];
	        }
	    }
	    
	    return a.back();
	}
};