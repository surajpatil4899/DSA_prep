#include<bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		
		int i, count = 0;
		for(i=0;i<n/2;i++){
		 if(s[i] != s[n-1-i])
		 count++;
		}

		if(count <= k){
		  if(n%2==1)
		   cout<<"YES"<<endl;
		   else if((k-count)%2==0)
		    cout<<"YES"<<endl;
           else
             cout<<"NO"<<endl;
		}
		else cout<<"NO"<<endl;

	}
}