#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(string &s){
	map<char,int> frequency;
	for(auto c: s){
		frequency[c]++;
	}
	int maxi = 0;
	for(auto c: s){
         maxi = max(maxi, frequency[c]);
	}
   return maxi<=s.size()/2;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	  int n;
	  cin>>n;
	  string s;
	  cin>>s;
	  if(n%2 != 0){ cout<<"NO"<<endl;}
	  else{
	  	if(isPossible(s)){
	  		sort(s.begin(), s.end());
	  
              reverse(s.begin()+n/2,s.end());
	  	cout<<"YES"<<endl;
	  	cout<<s<<endl; 
	  }
	  else{
	  	cout<<"NO"<<endl;
	  }
	  }
	}
	return 0;
}
