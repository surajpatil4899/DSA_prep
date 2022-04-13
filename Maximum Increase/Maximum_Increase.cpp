#include<bits/stdc++.h>
using namespace std;



int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];

	int count = 1, maxi = 1;

	for(int i=1;i<n;i++){
		if(a[i]>a[i-1]) count++;
		else{
			if(count>maxi) maxi = count;
			count = 1;
		}
	}
	if(count>maxi) maxi = count;
	cout<<maxi<<endl;
}