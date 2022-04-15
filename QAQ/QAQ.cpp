#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;
	int n = s.size();
	int ans = 0;
	for(int i=0;i<n-2;i++){
	    if(s[i]!='Q') continue;
	    for(int j=i+1;j<n-1;j++){
	        if(s[j]=='A'){
	            for(int k=j+1;k<n;k++){
	                if(s[k]=='Q') ans++;
	            }
	        }
	    }
	}
	
	cout<<ans<<endl;
	return 0;
}
