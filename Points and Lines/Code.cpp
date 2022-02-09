#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
    unordered_set<int> x_a;
    unordered_set<int> y_a;
	for(int i=0;i<n;i++){
		long long x,y;
		cin>>x>>y;
	    x_a.insert(x);
	    y_a.insert(y);
	}
	long long x_count = x_a.size(), y_count = y_a.size();
     
        cout<<x_count+y_count<<endl;
	}
}