#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;
	vector<char> st;
	for(int i=0;i<s.size();i++){
	    if(st.size()==0) st.push_back(s[i]);
	    else{
	        if(st[st.size()-1]==s[i]) st.pop_back();
	        else st.push_back(s[i]);
	    }
	}	    
	    if(st.size()==0) cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;
	return 0;
}
