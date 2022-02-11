#include<bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
    string s;
    cin>>s;

    int count0 = 0, count1 = 0;
    for(int i=0;i<n;i++){
    	if(s[i]=='1') count1++;
    	else if(s[i]=='0') count0++;
    }
  if(n%2==0){
  	if(count0==count1) cout<<"YES"<<endl;
  	else if(count0%2==0 && count1%2==0)
  		cout<<"YES"<<endl;
  	else cout<<"NO"<<endl;
  }
    else{
    	cout<<"YES"<<endl;
    }

  }
}