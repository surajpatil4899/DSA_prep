#include<bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	int count = 0;
	for(int i=0;i<v.size();i++){
		if(v[i]==i+1){
			count++;
			v.insert(v.begin() + i,i+2);
		}
	}
    
    cout<<count<<endl;
	}
}